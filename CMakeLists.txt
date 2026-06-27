cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(rover_control LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ─────────────────────────────────────────────────────────────
# Build mode selection
# BUILD_MODE can be:
#   "native"  (default) – build unit tests with host toolchain
#   "esp32"             – build firmware for ESP32 target
# ─────────────────────────────────────────────────────────────
set(BUILD_MODE "native" CACHE STRING
    "Build mode: 'native' for unit tests, 'esp32' for target firmware")

set_property(CACHE BUILD_MODE PROPERTY STRINGS native esp32)

# Detect cross-compilation (toolchain file) as a hint that ESP32 mode is intended
if(DEFINED CMAKE_TOOLCHAIN_FILE AND BUILD_MODE STREQUAL "native")
    message(WARNING
        "CMAKE_TOOLCHAIN_FILE is set but BUILD_MODE is 'native'. "
        "Forcing BUILD_MODE to 'esp32'. To suppress this warning, set "
        "-DBUILD_MODE=esp32 explicitly.")
    set(BUILD_MODE "esp32")
endif()

# ─────────────────────────────────────────────────────────────
# Helper: print what we are going to build
# ─────────────────────────────────────────────────────────────
message(STATUS "")
message(STATUS "╔══════════════════════════════════════════╗")
message(STATUS "║   Rover Control - Build Mode: ${BUILD_MODE}     ║")
message(STATUS "╚══════════════════════════════════════════╝")
message(STATUS "")

# ─────────────────────────────────────────────────────────────
# ESP32 build mode
# ─────────────────────────────────────────────────────────────
if(BUILD_MODE STREQUAL "esp32")
    # Validate that we have a toolchain configured
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        message(FATAL_ERROR
            "\n"
            "CMAKE_TOOLCHAIN_FILE is not set but BUILD_MODE is 'esp32'.\n"
            "Example configuration:\n"
            "  cmake -S . -B build/esp32 \\\n"
            "        -DBUILD_MODE=esp32 \\\n"
            "        -DCMAKE_TOOLCHAIN_FILE=${IDF_PATH}/tools/cmake/toolchain/esp32_toolchain.cmake\n")
    endif()

    add_subdirectory(src/rover-esp32)

else()
    # ─────────────────────────────────────────────────────────────
    # Native (host) build mode – unit tests
    # ─────────────────────────────────────────────────────────────
    message(STATUS "Native build: compiling host unit tests")
    message(STATUS "Recommended: cmake --build build/native --target rover_tests -j")
    message(STATUS "Then run:     ctest --test-dir build/native --output-on-failure")
    message(STATUS "")

    include(CTest)
    enable_testing()

    add_subdirectory(src)
    add_subdirectory(tests)

endif()

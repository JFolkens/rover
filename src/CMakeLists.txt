# ─────────────────────────────────────────────────────────────
# Native / Host build only:
#   rover_core  – platform-agnostic business logic
#   rover_mock  – mock implementations for testing
# ─────────────────────────────────────────────────────────────
if(BUILD_MODE STREQUAL "esp32")
    message(FATAL_ERROR
        "src/CMakeLists.txt must not be included when BUILD_MODE=esp32. "
        "The ESP32 subdirectory (src/rover-esp32) should be added instead.")
endif()

# Helper macro to collect all source files in a directory tree
macro(rover_collect_sources _target_var _dir)
    file(GLOB_RECURSE ${_target_var}
        CONFIGURE_DEPENDS
        ${_dir}/*.cpp
        ${_dir}/*.cc
        ${_dir}/*.cxx
        ${_dir}/*.c
    )
endmacro()

# ── rover_core ───────────────────────────────────────────────
add_library(rover_core
    rover-core/chassis/chassis.cpp
    rover-core/drivetrain/drivetrain.cpp
)

# Derive all sources automatically as a fallback (keeps list maintainable)
rover_collect_sources(_rover_core_sources ${CMAKE_CURRENT_SOURCE_DIR}/rover-core)
target_sources(rover_core PRIVATE ${_rover_core_sources})

target_include_directories(rover_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}           # allows #include "rover-core/..."
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-core/chassis
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-core/drivetrain
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-core/sensors
)

target_compile_features(rover_core PUBLIC cxx_std_17)

# ── rover_mock ───────────────────────────────────────────────
add_library(rover_mock
    rover-mock/drivetrain/motor_mock.cpp
    rover-mock/drivetrain/encoder_mock.cpp
    rover-mock/chassis/mock_chassis.cpp
    rover-mock/sensors/imu_mock.cpp
)

rover_collect_sources(_rover_mock_sources ${CMAKE_CURRENT_SOURCE_DIR}/rover-mock)
target_sources(rover_mock PRIVATE ${_rover_mock_sources})

target_include_directories(rover_mock
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-mock
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-mock/chassis
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-mock/drivetrain
        ${CMAKE_CURRENT_SOURCE_DIR}/rover-mock/sensors
)

target_link_libraries(rover_mock PUBLIC rover_core)

# ESP32-specific build configuration
# This is included when BUILD_MODE is set to "esp32"

# Assumes the ESP-IDF environment is set up and toolchain file is configured
# Build command: cmake -S . -B build/esp32 -DBUILD_MODE=esp32 -DCMAKE_TOOLCHAIN_FILE=$IDF_PATH/tools/cmake/toolchain/esp32_toolchain.cmake

add_executable(rover_esp32_app
    main.cpp
    drivetrain/motor_esp32.cpp
)

target_include_directories(rover_esp32_app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../rover-core
        ${CMAKE_CURRENT_SOURCE_DIR}/../rover-core/drivetrain
        ${CMAKE_CURRENT_SOURCE_DIR}/../rover-core/chassis
        ${CMAKE_CURRENT_SOURCE_DIR}/../rover-core/sensors
)

# Link against the core library
target_link_libraries(rover_esp32_app
    PRIVATE
        rover_core
)

# If using ESP-IDF, link against required ESP-IDF components
# This would typically be: esp-idf, freertos, driver, etc.
# Uncomment and adjust based on your ESP-IDF setup:
# target_link_libraries(rover_esp32_app PRIVATE esp-idf)

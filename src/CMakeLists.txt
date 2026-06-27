add_library(rover_core
    rover/drivetrain/motor_mock.cpp
    rover/drivetrain/encoder_mock.cpp
    rover/drivetrain/wheel_controller.cpp
    rover/drivetrain/drivetrain.cpp
    rover/chassis/chassis.cpp
    rover/chassis/mock_chassis.cpp
    rover/sensors/imu_mock.cpp
)

target_include_directories(rover_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

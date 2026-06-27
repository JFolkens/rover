find_package(GTest REQUIRED)

add_executable(rover_tests
    drivetrain/motor_tests.cpp
    drivetrain/encoder_tests.cpp
    drivetrain/wheel_controller_tests.cpp
    drivetrain/drivetrain_tests.cpp
    chassis/command_tests.cpp
    chassis/chassis_tests.cpp
    sensors/sensor_tests.cpp
)

target_link_libraries(rover_tests
    PRIVATE
        rover_core
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(rover_tests)

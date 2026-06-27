#include <gtest/gtest.h>

#include "rover/chassis/chassis_command.h"
#include "rover/chassis/mock_chassis.h"
#include "rover/drivetrain/motor_mock.h"
#include "rover/drivetrain/encoder_mock.h"
#include "rover/drivetrain/wheel_controller.h"
#include "rover/drivetrain/drivetrain.h"
#include "rover/chassis/chassis.h"

namespace rover::tests::chassis
{

    TEST(MockChassisTest, RecordsMoveForwardCommand)
    {
        rover::chassis::MockChassis chassis;
        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::MoveForward;
        cmd.distance = 1.0f;
        cmd.speed = 50.0f;

        chassis.execute(cmd);

        EXPECT_EQ(chassis.lastCommand().command, rover::chassis::ChassisCommand::Type::MoveForward);
        EXPECT_FLOAT_EQ(chassis.lastCommand().distance, 1.0f);
        EXPECT_TRUE(chassis.isExecuting());
    }

    TEST(MockChassisTest, RecordsStopCommand)
    {
        rover::chassis::MockChassis chassis;
        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::Stop;

        chassis.execute(cmd);

        EXPECT_TRUE(chassis.wasStopped());
        EXPECT_FALSE(chassis.isExecuting());
    }

    TEST(ChassisTest, MoveForwardAppliesSameSpeedToWheels)
    {
        rover::drivetrain::MotorMock motors[4];
        rover::drivetrain::EncoderMock encoders[4];
        rover::drivetrain::WheelController wheels[4] = {
            rover::drivetrain::WheelController(motors[0], encoders[0]),
            rover::drivetrain::WheelController(motors[1], encoders[1]),
            rover::drivetrain::WheelController(motors[2], encoders[2]),
            rover::drivetrain::WheelController(motors[3], encoders[3]),
        };
        rover::drivetrain::Drivetrain drivetrain(wheels[0], wheels[1], wheels[2], wheels[3]);
        rover::chassis::Chassis chassis(drivetrain);

        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::MoveForward;
        cmd.distance = 1.0f;
        cmd.speed = 60.0f;

        chassis.execute(cmd);

        EXPECT_EQ(motors[0].power(), 60);
        EXPECT_EQ(motors[1].power(), 60);
        EXPECT_EQ(motors[2].power(), 60);
        EXPECT_EQ(motors[3].power(), 60);
    }

    TEST(ChassisTest, MoveReverseNegatesSpeed)
    {
        rover::drivetrain::MotorMock motors[4];
        rover::drivetrain::EncoderMock encoders[4];
        rover::drivetrain::WheelController wheels[4] = {
            rover::drivetrain::WheelController(motors[0], encoders[0]),
            rover::drivetrain::WheelController(motors[1], encoders[1]),
            rover::drivetrain::WheelController(motors[2], encoders[2]),
            rover::drivetrain::WheelController(motors[3], encoders[3]),
        };
        rover::drivetrain::Drivetrain drivetrain(wheels[0], wheels[1], wheels[2], wheels[3]);
        rover::chassis::Chassis chassis(drivetrain);

        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::MoveReverse;
        cmd.distance = 1.0f;
        cmd.speed = 40.0f;

        chassis.execute(cmd);

        EXPECT_EQ(motors[0].power(), -40);
        EXPECT_EQ(motors[1].power(), -40);
        EXPECT_EQ(motors[2].power(), -40);
        EXPECT_EQ(motors[3].power(), -40);
    }

    TEST(ChassisTest, TurnLeftSlowsLeftWheels)
    {
        rover::drivetrain::MotorMock motors[4];
        rover::drivetrain::EncoderMock encoders[4];
        rover::drivetrain::WheelController wheels[4] = {
            rover::drivetrain::WheelController(motors[0], encoders[0]),
            rover::drivetrain::WheelController(motors[1], encoders[1]),
            rover::drivetrain::WheelController(motors[2], encoders[2]),
            rover::drivetrain::WheelController(motors[3], encoders[3]),
        };
        rover::drivetrain::Drivetrain drivetrain(wheels[0], wheels[1], wheels[2], wheels[3]);
        rover::chassis::Chassis chassis(drivetrain);

        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::TurnLeft;
        cmd.distance = 45.0f;
        cmd.speed = 100.0f;

        chassis.execute(cmd);

        EXPECT_EQ(motors[0].power(), 50);  // left wheel
        EXPECT_EQ(motors[1].power(), 100); // right wheel
        EXPECT_EQ(motors[2].power(), 50);  // left wheel
        EXPECT_EQ(motors[3].power(), 100); // right wheel
    }

    TEST(ChassisTest, TurnRightSlowsRightWheels)
    {
        rover::drivetrain::MotorMock motors[4];
        rover::drivetrain::EncoderMock encoders[4];
        rover::drivetrain::WheelController wheels[4] = {
            rover::drivetrain::WheelController(motors[0], encoders[0]),
            rover::drivetrain::WheelController(motors[1], encoders[1]),
            rover::drivetrain::WheelController(motors[2], encoders[2]),
            rover::drivetrain::WheelController(motors[3], encoders[3]),
        };
        rover::drivetrain::Drivetrain drivetrain(wheels[0], wheels[1], wheels[2], wheels[3]);
        rover::chassis::Chassis chassis(drivetrain);

        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::TurnRight;
        cmd.distance = 45.0f;
        cmd.speed = 100.0f;

        chassis.execute(cmd);

        EXPECT_EQ(motors[0].power(), 100); // left wheel
        EXPECT_EQ(motors[1].power(), 50);  // right wheel
        EXPECT_EQ(motors[2].power(), 100); // left wheel
        EXPECT_EQ(motors[3].power(), 50);  // right wheel
    }

    TEST(ChassisTest, StopSetsAllWheelsToZero)
    {
        rover::drivetrain::MotorMock motors[4];
        rover::drivetrain::EncoderMock encoders[4];
        rover::drivetrain::WheelController wheels[4] = {
            rover::drivetrain::WheelController(motors[0], encoders[0]),
            rover::drivetrain::WheelController(motors[1], encoders[1]),
            rover::drivetrain::WheelController(motors[2], encoders[2]),
            rover::drivetrain::WheelController(motors[3], encoders[3]),
        };
        rover::drivetrain::Drivetrain drivetrain(wheels[0], wheels[1], wheels[2], wheels[3]);
        rover::chassis::Chassis chassis(drivetrain);

        rover::chassis::ChassisCommand move_cmd;
        move_cmd.command = rover::chassis::ChassisCommand::Type::MoveForward;
        move_cmd.speed = 75.0f;
        chassis.execute(move_cmd);

        rover::chassis::ChassisCommand stop_cmd;
        stop_cmd.command = rover::chassis::ChassisCommand::Type::Stop;
        chassis.execute(stop_cmd);

        EXPECT_EQ(motors[0].power(), 0);
        EXPECT_EQ(motors[1].power(), 0);
        EXPECT_EQ(motors[2].power(), 0);
        EXPECT_EQ(motors[3].power(), 0);
    }

} // namespace rover::tests::chassis

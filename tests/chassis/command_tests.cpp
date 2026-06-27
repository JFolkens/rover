#include <gtest/gtest.h>

#include "rover/chassis/chassis_command.h"

namespace rover::tests::chassis
{

    TEST(ChassisCommandTest, InitializesMoveForwardCommand)
    {
        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::MoveForward;
        cmd.distance = 1.0f;
        cmd.speed = 75.0f;

        EXPECT_EQ(cmd.command, rover::chassis::ChassisCommand::Type::MoveForward);
        EXPECT_FLOAT_EQ(cmd.distance, 1.0f);
        EXPECT_FLOAT_EQ(cmd.speed, 75.0f);
    }

    TEST(ChassisCommandTest, InitializesTurnLeftCommand)
    {
        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::TurnLeft;
        cmd.distance = 45.0f;
        cmd.speed = 50.0f;

        EXPECT_EQ(cmd.command, rover::chassis::ChassisCommand::Type::TurnLeft);
        EXPECT_FLOAT_EQ(cmd.distance, 45.0f);
    }

    TEST(ChassisCommandTest, InitializesStopCommand)
    {
        rover::chassis::ChassisCommand cmd;
        cmd.command = rover::chassis::ChassisCommand::Type::Stop;

        EXPECT_EQ(cmd.command, rover::chassis::ChassisCommand::Type::Stop);
    }

} // namespace rover::tests::chassis

#include <gtest/gtest.h>

#include "rover-mock/drivetrain/motor_mock.h"

namespace rover::tests::drivetrain
{

    TEST(MotorMockTest, SetsAndReturnsPower)
    {
        rover::drivetrain::MotorMock motor;
        motor.setPower(75);
        EXPECT_EQ(motor.power(), 75);
    }

} // namespace rover::tests::drivetrain

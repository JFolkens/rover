#include <gtest/gtest.h>

#include "rover/drivetrain/motor_mock.h"
#include "rover/drivetrain/encoder_mock.h"
#include "rover/drivetrain/wheel_controller.h"
#include "rover/drivetrain/drivetrain.h"

namespace rover::tests::drivetrain
{

    TEST(DrivetrainTest, AppliesDifferentLeftAndRightSpeeds)
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

        drivetrain.drive(40, 60);

        EXPECT_EQ(motors[0].power(), 40);
        EXPECT_EQ(motors[1].power(), 60);
        EXPECT_EQ(motors[2].power(), 40);
        EXPECT_EQ(motors[3].power(), 60);
    }

} // namespace rover::tests::drivetrain

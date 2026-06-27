#include <gtest/gtest.h>

#include "rover/drivetrain/motor_mock.h"
#include "rover/drivetrain/encoder_mock.h"
#include "rover/drivetrain/wheel_controller.h"

namespace rover::tests::drivetrain
{

    TEST(WheelControllerTest, AppliesTargetSpeedToMotor)
    {
        rover::drivetrain::MotorMock motor;
        rover::drivetrain::EncoderMock encoder;
        rover::drivetrain::WheelController controller(motor, encoder);

        controller.setTargetSpeed(50);

        EXPECT_EQ(motor.power(), 50);
        EXPECT_EQ(controller.targetSpeed(), 50);
    }

    TEST(WheelControllerTest, ResetsEncoderAndTracksTicksChanges)
    {
        rover::drivetrain::MotorMock motor;
        rover::drivetrain::EncoderMock encoder;
        rover::drivetrain::WheelController controller(motor, encoder);

        encoder.setTicks(42);
        EXPECT_EQ(controller.encoderTicks(), 42);

        controller.resetEncoder();
        EXPECT_EQ(controller.encoderTicks(), 0);
    }

} // namespace rover::tests::drivetrain

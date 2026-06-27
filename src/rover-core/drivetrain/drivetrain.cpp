#include "drivetrain.h"

namespace rover::drivetrain
{

    Drivetrain::Drivetrain(WheelController &front_left, WheelController &front_right,
                           WheelController &rear_left, WheelController &rear_right)
        : front_left_(front_left), front_right_(front_right),
          rear_left_(rear_left), rear_right_(rear_right) {}

    void Drivetrain::drive(int left_speed, int right_speed)
    {
        current_left_speed_ = left_speed;
        current_right_speed_ = right_speed;

        front_left_.setTargetSpeed(left_speed);
        rear_left_.setTargetSpeed(left_speed);
        front_right_.setTargetSpeed(right_speed);
        rear_right_.setTargetSpeed(right_speed);
    }

    void Drivetrain::stop()
    {
        drive(0, 0);
    }

    void Drivetrain::resetEncoders()
    {
        front_left_.resetEncoder();
        front_right_.resetEncoder();
        rear_left_.resetEncoder();
        rear_right_.resetEncoder();
    }

    int Drivetrain::frontLeftTicks() const
    {
        return front_left_.encoderTicks();
    }

    int Drivetrain::frontRightTicks() const
    {
        return front_right_.encoderTicks();
    }

    int Drivetrain::rearLeftTicks() const
    {
        return rear_left_.encoderTicks();
    }

    int Drivetrain::rearRightTicks() const
    {
        return rear_right_.encoderTicks();
    }

} // namespace rover::drivetrain

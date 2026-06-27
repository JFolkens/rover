#include "drivetrain.h"

namespace rover::drivetrain
{

    Drivetrain::Drivetrain(WheelController &front_left, WheelController &front_right,
                           WheelController &rear_left, WheelController &rear_right)
        : front_left_(front_left), front_right_(front_right),
          rear_left_(rear_left), rear_right_(rear_right) {}

    void Drivetrain::drive(DriveDirection direction, int speed)
    {
        current_direction_ = direction;
        current_speed_ = speed;

        int motor_speed = speed;
        if (direction == DriveDirection::Reverse)
        {
            motor_speed = -speed;
        }
        else if (direction == DriveDirection::Stop)
        {
            motor_speed = 0;
        }

        front_left_.setTargetSpeed(motor_speed);
        front_right_.setTargetSpeed(motor_speed);
        rear_left_.setTargetSpeed(motor_speed);
        rear_right_.setTargetSpeed(motor_speed);
    }

    void Drivetrain::stop()
    {
        drive(DriveDirection::Stop, 0);
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

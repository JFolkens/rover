#pragma once

#include "wheel_controller.h"

namespace rover::drivetrain
{

    enum class DriveDirection
    {
        Forward,
        Reverse,
        Stop
    };

    class Drivetrain
    {
    public:
        Drivetrain(WheelController &front_left, WheelController &front_right,
                   WheelController &rear_left, WheelController &rear_right);

        void drive(DriveDirection direction, int speed);
        void stop();
        void resetEncoders();

        int frontLeftTicks() const;
        int frontRightTicks() const;
        int rearLeftTicks() const;
        int rearRightTicks() const;

    private:
        WheelController &front_left_;
        WheelController &front_right_;
        WheelController &rear_left_;
        WheelController &rear_right_;
        DriveDirection current_direction_{DriveDirection::Stop};
        int current_speed_{0};
    };

} // namespace rover::drivetrain

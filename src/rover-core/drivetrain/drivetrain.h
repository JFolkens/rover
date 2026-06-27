#pragma once

#include "rover-core/drivetrain/wheel_controller.h"

namespace rover::drivetrain
{

    class Drivetrain
    {
    public:
        Drivetrain(WheelController &front_left, WheelController &front_right,
                   WheelController &rear_left, WheelController &rear_right);

        void drive(int left_speed, int right_speed);
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
        int current_left_speed_{0};
        int current_right_speed_{0};
    };

} // namespace rover::drivetrain

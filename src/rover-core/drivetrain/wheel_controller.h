#pragma once

#include "motor_interface.h"
#include "encoder_interface.h"

namespace rover::drivetrain
{

    class WheelController
    {
    public:
        WheelController(MotorInterface &motor, EncoderInterface &encoder);

        void setTargetSpeed(int percent);
        int targetSpeed() const;
        void resetEncoder();
        int encoderTicks() const;

    private:
        MotorInterface &motor_;
        EncoderInterface &encoder_;
        int target_speed_{0};
    };

} // namespace rover::drivetrain

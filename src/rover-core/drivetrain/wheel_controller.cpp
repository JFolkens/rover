#include "wheel_controller.h"

namespace rover::drivetrain
{

    WheelController::WheelController(MotorInterface &motor, EncoderInterface &encoder)
        : motor_(motor), encoder_(encoder) {}

    void WheelController::setTargetSpeed(int percent)
    {
        target_speed_ = percent;
        motor_.setPower(percent);
    }

    int WheelController::targetSpeed() const
    {
        return target_speed_;
    }

    void WheelController::resetEncoder()
    {
        encoder_.reset();
    }

    int WheelController::encoderTicks() const
    {
        return encoder_.ticks();
    }

} // namespace rover::drivetrain

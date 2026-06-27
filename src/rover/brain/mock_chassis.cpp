#include "mock_chassis.h"

namespace rover::brain
{

    void MockChassis::driveForward(int speed)
    {
        last_forward_speed_ = speed;
        stopped_ = false;
    }

    void MockChassis::driveReverse(int speed)
    {
        last_reverse_speed_ = speed;
        stopped_ = false;
    }

    void MockChassis::stop()
    {
        stopped_ = true;
        last_forward_speed_ = 0;
        last_reverse_speed_ = 0;
    }

    void MockChassis::resetEncoders()
    {
        for (int i = 0; i < 4; ++i)
        {
            encoder_ticks_[i] = 0;
        }
    }

    int MockChassis::getEncoderTicks(int wheel_id) const
    {
        if (wheel_id >= 0 && wheel_id < 4)
        {
            return encoder_ticks_[wheel_id];
        }
        return 0;
    }

    void MockChassis::setEncoderTicks(int wheel_id, int ticks)
    {
        if (wheel_id >= 0 && wheel_id < 4)
        {
            encoder_ticks_[wheel_id] = ticks;
        }
    }

} // namespace rover::brain

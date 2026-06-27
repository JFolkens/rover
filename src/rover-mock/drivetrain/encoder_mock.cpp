#include "encoder_mock.h"

namespace rover::drivetrain
{

    void EncoderMock::reset()
    {
        ticks_ = 0;
    }

    int EncoderMock::ticks() const
    {
        return ticks_;
    }

    void EncoderMock::setTicks(int ticks)
    {
        ticks_ = ticks;
    }

} // namespace rover::drivetrain

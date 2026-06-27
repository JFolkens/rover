#pragma once

#include "rover-core/drivetrain/encoder_interface.h"

namespace rover::drivetrain
{

    class EncoderMock : public EncoderInterface
    {
    public:
        void reset() override;
        int ticks() const override;

        // Mock methods
        void setTicks(int ticks);

    private:
        int ticks_{0};
    };

} // namespace rover::drivetrain

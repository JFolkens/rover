#pragma once

namespace rover::drivetrain
{

    class EncoderInterface
    {
    public:
        virtual ~EncoderInterface() = default;

        virtual void reset() = 0;
        virtual int ticks() const = 0;
    };

} // namespace rover::drivetrain

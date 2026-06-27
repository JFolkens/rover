#pragma once

namespace rover::drivetrain
{

    class MotorInterface
    {
    public:
        virtual ~MotorInterface() = default;

        virtual void setPower(int percent) = 0;
        virtual int power() const = 0;
    };

} // namespace rover::drivetrain

#pragma once

#include "rover-core/drivetrain/motor_interface.h"

namespace rover::drivetrain
{

    class MotorMock : public MotorInterface
    {
    public:
        void setPower(int percent) override;
        int power() const override;

    private:
        int power_{0};
    };

} // namespace rover::drivetrain

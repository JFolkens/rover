#include "motor_mock.h"

namespace rover::drivetrain
{

    void MotorMock::setPower(int percent)
    {
        power_ = percent;
    }

    int MotorMock::power() const
    {
        return power_;
    }

} // namespace rover::drivetrain

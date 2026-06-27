#include "imu_mock.h"

namespace rover::sensors
{

    void ImuMock::setAcceleration(float x, float y, float z)
    {
        accel_x_ = x;
        accel_y_ = y;
        accel_z_ = z;
    }

} // namespace rover::sensors

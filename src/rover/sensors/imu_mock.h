#pragma once

#include "imu_interface.h"

namespace rover::sensors
{

    class ImuMock : public ImuInterface
    {
    public:
        float getAccelerationX() const override { return accel_x_; }
        float getAccelerationY() const override { return accel_y_; }
        float getAccelerationZ() const override { return accel_z_; }

        // Mock methods
        void setAcceleration(float x, float y, float z);

    private:
        float accel_x_{0.0f};
        float accel_y_{0.0f};
        float accel_z_{0.0f};
    };

} // namespace rover::sensors
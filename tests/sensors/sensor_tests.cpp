#include <gtest/gtest.h>

#include "rover-core/sensors/imu_interface.h"

#include "rover-mock/sensors/imu_mock.h"

namespace rover::tests::sensors
{

    TEST(ImuMockTest, SetAndGetAcceleration)
    {
        rover::sensors::ImuMock imu;

        imu.setAcceleration(1.5f, -2.0f, 9.8f);

        EXPECT_FLOAT_EQ(imu.getAccelerationX(), 1.5f);
        EXPECT_FLOAT_EQ(imu.getAccelerationY(), -2.0f);
        EXPECT_FLOAT_EQ(imu.getAccelerationZ(), 9.8f);
    }

} // namespace rover::tests::sensors

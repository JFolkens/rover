#include <gtest/gtest.h>

#include "rover-mock/drivetrain/encoder_mock.h"

namespace rover::tests::drivetrain
{

    TEST(EncoderMockTest, TracksTicksAndReset)
    {
        rover::drivetrain::EncoderMock encoder;
        encoder.setTicks(100);
        EXPECT_EQ(encoder.ticks(), 100);
        encoder.reset();
        EXPECT_EQ(encoder.ticks(), 0);
    }

} // namespace rover::tests::drivetrain

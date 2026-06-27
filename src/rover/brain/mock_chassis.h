#pragma once

#include "chassis_interface.h"

namespace rover::brain {

class MockChassis : public ChassisInterface {
public:
    void driveForward(int speed) override;
    void driveReverse(int speed) override;
    void stop() override;
    void resetEncoders() override;

    int getEncoderTicks(int wheel_id) const override;

    // Test helpers
    int lastForwardSpeed() const { return last_forward_speed_; }
    int lastReverseSpeed() const { return last_reverse_speed_; }
    bool wasStopped() const { return stopped_; }
    void setEncoderTicks(int wheel_id, int ticks);

private:
    int last_forward_speed_{0};
    int last_reverse_speed_{0};
    bool stopped_{false};
    int encoder_ticks_[4]{0, 0, 0, 0};
};

}  // namespace rover::brain

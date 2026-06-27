#pragma once

namespace rover::brain {

class ChassisInterface {
public:
    virtual ~ChassisInterface() = default;

    virtual void driveForward(int speed) = 0;
    virtual void driveReverse(int speed) = 0;
    virtual void stop() = 0;
    virtual void resetEncoders() = 0;

    virtual int getEncoderTicks(int wheel_id) const = 0;
};

}  // namespace rover::brain

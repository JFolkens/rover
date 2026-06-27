#pragma once

namespace rover::sensors
{

    class ImuInterface
    {
    public:
        virtual ~ImuInterface() = default;

        virtual float getAccelerationX() const = 0;
        virtual float getAccelerationY() const = 0;
        virtual float getAccelerationZ() const = 0;
    };

} // namespace rover::sensors

#pragma once

#include "rover-core/drivetrain/drivetrain.h"
#include "chassis_interface.h"

namespace rover::chassis
{

    class Chassis : public ChassisInterface
    {
    public:
        explicit Chassis(rover::drivetrain::Drivetrain &drivetrain, float wheel_radius_cm = 3.0f, float track_width_cm = 10.0f);

        void execute(const ChassisCommand &cmd) override;
        bool isExecuting() const override;

        void stop();

    private:
        rover::drivetrain::Drivetrain &drivetrain_;
        float wheel_radius_cm_;
        float track_width_cm_;

        ChassisCommand current_command_;
        bool executing_{false};

        int starting_left_ticks_{0};
        int starting_right_ticks_{0};
    };

} // namespace rover::chassis

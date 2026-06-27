#include "chassis.h"

#include "rover/drivetrain/drivetrain.h"

#include <cmath>

namespace rover::chassis
{

    Chassis::Chassis(rover::drivetrain::Drivetrain &drivetrain, float wheel_radius_cm, float track_width_cm)
        : drivetrain_(drivetrain), wheel_radius_cm_(wheel_radius_cm),
          track_width_cm_(track_width_cm) {}

    void Chassis::execute(const ChassisCommand &cmd)
    {
        current_command_ = cmd;
        executing_ = true;

        drivetrain_.resetEncoders();
        starting_left_ticks_ = 0;
        starting_right_ticks_ = 0;

        switch (cmd.command)
        {
        case ChassisCommand::Type::MoveForward:
            drivetrain_.drive(static_cast<int>(cmd.speed), static_cast<int>(cmd.speed));
            break;
        case ChassisCommand::Type::MoveReverse:
            drivetrain_.drive(static_cast<int>(-cmd.speed), static_cast<int>(-cmd.speed));
            break;
        case ChassisCommand::Type::TurnLeft:
        {
            // Left wheels slower, right wheels faster
            int left_speed = static_cast<int>(cmd.speed * 0.5f);
            int right_speed = static_cast<int>(cmd.speed);
            drivetrain_.drive(left_speed, right_speed);
            break;
        }
        case ChassisCommand::Type::TurnRight:
        {
            // Right wheels slower, left wheels faster
            int left_speed = static_cast<int>(cmd.speed);
            int right_speed = static_cast<int>(cmd.speed * 0.5f);
            drivetrain_.drive(left_speed, right_speed);
            break;
        }
        case ChassisCommand::Type::Stop:
            drivetrain_.stop();
            executing_ = false;
            break;
        }
    }

    bool Chassis::isExecuting() const
    {
        return executing_;
    }

    void Chassis::stop()
    {
        executing_ = false;
        drivetrain_.stop();
    }

} // namespace rover::chassis

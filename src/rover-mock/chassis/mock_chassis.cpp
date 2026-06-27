#include "mock_chassis.h"

namespace rover::chassis
{

    void MockChassis::execute(const ChassisCommand &cmd)
    {
        last_command_ = cmd;
        stopped_ = (cmd.command == ChassisCommand::Type::Stop);
    }

    bool MockChassis::isExecuting() const
    {
        return !stopped_;
    }

} // namespace rover::chassis

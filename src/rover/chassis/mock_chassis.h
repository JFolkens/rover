#pragma once

#include "chassis_interface.h"

namespace rover::chassis
{

    class MockChassis : public ChassisInterface
    {
    public:
        void execute(const ChassisCommand &cmd) override;
        bool isExecuting() const override;

        // Test helpers
        ChassisCommand lastCommand() const { return last_command_; }
        bool wasStopped() const { return stopped_; }

    private:
        ChassisCommand last_command_;
        bool stopped_{false};
    };

} // namespace rover::chassis

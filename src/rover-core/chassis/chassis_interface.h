#pragma once

#include "chassis_command.h"

namespace rover::chassis {

class ChassisInterface {
public:
    virtual ~ChassisInterface() = default;

    virtual void execute(const ChassisCommand& cmd) = 0;
    virtual bool isExecuting() const = 0;
};

}  // namespace rover::chassis

#pragma once

namespace rover::chassis {

struct ChassisCommand {
    enum class Type { MoveForward, MoveReverse, TurnLeft, TurnRight, Stop };

    Type command;
    float distance;  // meters for move, degrees for turn
    float speed;     // 0-100 percent
};

}  // namespace rover::chassis

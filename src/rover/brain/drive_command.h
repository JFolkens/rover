#pragma once

namespace rover::brain {

enum class Intent { Idle, MoveForward, MoveReverse, TurnLeft, TurnRight, Stop, Brake };

struct DriveCommand {
    Intent intent{Intent::Idle};
    int speed{0};  // 0-100, represents power percentage
    int turn_factor{0};  // -100 to 100 for steering; 0 = straight
};

}  // namespace rover::brain

#pragma once
#include "../include/vec.h"

class MoveInput {
public:
    vec3 input;
    bool upHold, downHold, leftHold, rightHold;
    bool turnLeftHold, turnRightHold;
    MoveInput();
};
#pragma once
#include "../include/vec.h"

class MoveInput {
public:
    vec3 input;
    bool upHold, downHold, leftHold, rightHold;
    bool turnLeftHold, turnRightHold;
    MoveInput();

    void getInputDown(unsigned char key);
    void getInputUp(unsigned char key);
};
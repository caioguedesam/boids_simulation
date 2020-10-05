#include "../include/move_input.h"

MoveInput::MoveInput() {
    input = vec3();
    upHold = downHold = leftHold = rightHold = false;
    turnLeftHold = turnRightHold = false;
}
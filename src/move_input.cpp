#include "../include/move_input.h"

MoveInput::MoveInput() {
    input = vec3();
    upHold = downHold = leftHold = rightHold = false;
    turnLeftHold = turnRightHold = false;
}

void MoveInput::getInputDown(unsigned char key) {
    if(key == 'w' && !upHold) {
        upHold = true;
        input.y = 1;
    }
    else if(key == 's' && !downHold) {
        downHold = true;
        input.y = -1;
    }
    else if(key == 'd' && !rightHold) {
        rightHold = true;
        input.x = 1;
    }
    else if(key == 'a' && !leftHold) {
        leftHold = true;
        input.x = -1;
    }
    else if(key == 'l' && !turnRightHold) {
        turnRightHold = true;
        input.z = 1;
    }
    else if(key == 'j' && !turnLeftHold) {
        turnLeftHold = true;
        input.z = -1;
    }
}

void MoveInput::getInputUp(unsigned char key) {
    if(key == 'w' && upHold) {
        upHold = false;
        input.y = 0;
    }
    else if(key == 's' && downHold) {
        downHold = false;
        input.y = 0;
    }
    else if(key == 'd' && rightHold) {
        rightHold = false;
        input.x = 0;
    }
    else if(key == 'a' && leftHold) {
        leftHold = false;
        input.x = 0;
    }
    else if(key == 'l' && turnRightHold) {
        turnRightHold = false;
        input.z = 0;
    }
    else if(key == 'j' && turnLeftHold) {
        turnLeftHold = false;
        input.z = 0;
    }
}
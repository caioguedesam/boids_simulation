#pragma once
#include "../include/boid.h"
#include "../include/move_input.h"

class CenterBoid : public Boid {
private:
    float angularSpeed;
public:
    CenterBoid(vec3 position, vec3 moveDirection, float moveSpeed, vec4 color, unsigned int id);
    
    void getInput(MoveInput input);
    vec3 rotateMoveDirection(quat rotationQuat);
    void print();

    void drawRightVector();
    void drawUpVector();
};
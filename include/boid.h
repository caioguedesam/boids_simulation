#pragma once
#include <iostream>
#include <vector>
#include "../include/vec.h"
#include "../include/deltatime.h"

class Boid {
private:
    vec3 position;
    vec3 moveDirection;
    float moveSpeed;

    vec4 color;

public:
    Boid();
    Boid(vec3 position, vec3 moveDirection, float moveSpeed);

    vec3 getPosition();
    vec3 getMoveDirection();
    void setMoveDirection(const vec3& dir);

    void update();
    void draw();

    void move();
    void printStats();
};
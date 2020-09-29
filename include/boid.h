#pragma once
#include <iostream>
#include <vector>
#include "../include/vec.h"
#include "../include/deltatime.h"

class Boid {
private:
    vec3 position;
    vec3 moveDirection;
    vec3 lastMoveDirection;
    float moveSpeed;
    float maxRotationAngle;
    vec2 size;
    float tipSize;

    vec4 color;

public:
    Boid();
    Boid(vec3 position, vec3 moveDirection, float moveSpeed);

    vec3 getPosition();
    vec3 getMoveDirection();
    void setMoveDirection(const vec3& dir);

    //GLfloat* getVertices();
    //GLfloat* getColors();

    void update();
    void draw();
    void drawTriangle(int a, int b, int c);
    void drawMoveDir();

    void move();
    void faceMoveDirection();
    void printStats();
};
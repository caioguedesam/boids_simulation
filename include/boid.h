#pragma once
#include <iostream>
#include <vector>
#include "../include/vec.h"
#include "../include/deltatime.h"
#include "../include/quaternion.h"
#include "../include/model.h"

class Boid {
protected:
    unsigned int id;
    
    vec3 position;
    vec3 moveDirection;
    vec3 lastMoveDirection;
    float moveSpeed;

    // Model information (will be changed later when using proper obj files)
    Model* model;
    /*vec2 size;
    float tipSize;
    std::vector<float> vertices;
    std::vector<int> triangles;
    std::vector<float> vertexColors;*/

    vec4 color;

public:
    Boid();
    Boid(vec3 position, vec3 moveDirection, float moveSpeed, Model* model, unsigned int id = 0);

    vec3 getPosition();
    vec3 getMoveDirection();
    void setMoveDirection(const vec3& dir);

    void update();
    void setMaterial();
    void draw();
    void drawMoveDir();

    void move();
    void faceMoveDirection();
};
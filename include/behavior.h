#pragma once
#include "../include/boid.h"
#include "../include/vec.h"
#include <vector>

class Behavior {
public:
    float weight = 0;
    virtual vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) = 0;
    Behavior(float weight);
};

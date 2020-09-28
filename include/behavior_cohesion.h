#pragma once
#include "../include/behavior.h"
#include "../include/vec.h"

class Cohesion : public Behavior {
public:
    Cohesion(float weight);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
};
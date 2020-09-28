#pragma once
#include "../include/behavior.h"
#include "../include/vec.h"

class Separation : public Behavior {
public:
    Separation(float weight);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
};
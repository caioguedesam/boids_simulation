#pragma once
#include "../include/behavior.h"
#include "../include/vec.h"

class Alignment : public Behavior {
public:
    Alignment(float weight);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
};
#pragma once
#include "../include/behavior.h"

class Alignment : public Behavior {
public:
    Alignment(float weight, float radius);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
private:
    float radius;
};
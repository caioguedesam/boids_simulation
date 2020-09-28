#pragma once
#include "../include/behavior.h"

class Separation : public Behavior {
public:
    Separation(float weight, float radius);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
private:
    float radius;
};
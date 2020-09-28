#pragma once
#include "../include/behavior.h"

class Cohesion : public Behavior {
public:
    Cohesion(float weight, float radius);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
private:
    float radius;
};
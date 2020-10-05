#pragma once
#include "../include/behavior.h"
#include "../include/center_boid.h"

class Follow : public Behavior {
public:
    Follow(float weight, CenterBoid* followTarget);
    vec3 calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) override;
private:
    CenterBoid* followTarget;
};
#include "../include/behavior_separation.h"

Separation::Separation(float weight, float radius) : Behavior(weight) {
    this->radius = radius;
}

vec3 Separation::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 result = vec3();
    vec3 boidPos = boid.getPosition();
    int count = 0;

    for(auto it = context.begin(); it != context.end(); it++) {
        if(*it == &boid) continue;

        vec3 contextPos = (*it)->getPosition();

        if(contextPos.sqrDist(boidPos) <= pow(radius,2)) {
            result += boidPos - contextPos;
            count++;
        }
    }
    if(count > 0) {
        result /= count;
    }
    return result.normalize();
}
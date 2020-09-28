#include "../include/behavior_cohesion.h"

Cohesion::Cohesion(float weight, float radius) : Behavior(weight) {
    this->radius = radius;
}

vec3 Cohesion::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 result = vec3();
    vec3 boidPos = boid.getPosition();
    int count = 0;

    for(auto it = context.begin(); it != context.end(); it++) {
        vec3 contextPos = (*it)->getPosition();

        if(contextPos.sqrDist(boidPos) <= pow(radius, 2)) {
            result += contextPos;
            count++;
        }
        
    }
    if(count > 0) {
        result /= count;
    }

    result = (result - boidPos);
    return result.normalize();
}
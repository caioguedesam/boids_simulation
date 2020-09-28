#include "../include/behavior_cohesion.h"

Cohesion::Cohesion(float weight) : Behavior(weight) {}

vec3 Cohesion::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 result = vec3();
    for(auto it = context.begin(); it != context.end(); it++) {
        result += (*it)->getPosition();
    }
    if(context.size() > 0)
        result /= context.size();
    return result.normalize();
}
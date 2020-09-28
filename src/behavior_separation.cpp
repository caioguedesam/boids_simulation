#include "../include/behavior_separation.h"

Separation::Separation(float weight) : Behavior(weight) {}

vec3 Separation::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 result = vec3();
    for(auto it = context.begin(); it != context.end(); it++) {
        result += boid.getPosition() - (*it)->getPosition();
    }
    if(context.size() > 0)
        result /= context.size();
    return result.normalize();
}
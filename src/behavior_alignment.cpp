#include "../include/behavior_alignment.h"

Alignment::Alignment(float weight) : Behavior(weight) {}

vec3 Alignment::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 result = vec3();
    for(auto it = context.begin(); it != context.end(); it++) {
        result += (*it)->getMoveDirection();
    }
    if(context.size() > 0)
        result /= context.size();
    return result.normalize();
}
#include "../include/behavior_follow.h"

Follow::Follow(float weight, CenterBoid* followTarget) : Behavior(weight) {
    this->followTarget = followTarget;

}

vec3 Follow::calculateMoveDirection(Boid& boid, const std::vector<Boid*> &context) {
    vec3 direction = followTarget->getPosition() - boid.getPosition();
    return direction.normalize();
}
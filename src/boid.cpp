#include "../include/boid.h"

Boid::Boid() {
    this->position = vec3(0, 0, 0);
    this->moveDirection = vec3(0, 0, 0);
    this->moveSpeed = 0;
    this->color = vec4();
}

Boid::Boid(vec3 position, vec3 moveDirection, float moveSpeed) {
    this->position = position;
    this->moveDirection = moveDirection;
    this->moveSpeed = moveSpeed;
    this->color = vec4(1,1,1,1);
}

vec3 Boid::getPosition() { return position; }
vec3 Boid::getMoveDirection() { return moveDirection; }
void Boid::setMoveDirection(const vec3& dir) { moveDirection = dir; }

void Boid::update() {
    move();
    printStats();
}

void Boid::draw() {
    glColor3f(color.x, color.y, color.z);
    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    // Currently, boid is solid cube;
    glutSolidCube(10);

    glPopMatrix();
}

void Boid::move() {
    position += moveDirection.normalize() * moveSpeed * deltaTime;
}

void Boid::printStats() {
    debugLog(moveDirection.normalize(), "MOVING WITH DIR: ");
}
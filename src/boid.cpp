#include "../include/boid.h"

Boid::Boid() {
    this->position = vec3(0, 0, 0);
    this->moveDirection = vec3(0, 0, 0);
    this->moveSpeed = 0;
    this->color = vec4();

    //this->behaviors = std::vector<Behavior*>();
    /*this->behaviors.push_back(Cohesion(1));
    this->behaviors.push_back(Alignment(2));
    this->behaviors.push_back(Separation(3));*/
}

Boid::Boid(vec3 position, vec3 moveDirection, float moveSpeed) {
    this->position = position;
    this->moveDirection = moveDirection;
    this->moveSpeed = moveSpeed;
    this->color = vec4(1,1,1,1);
}

vec3 Boid::getPosition() { return position; }
vec3 Boid::getMoveDirection() { return moveDirection; }

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
    /*std::cout << "Coh w: " << behaviors[0].weight << std::endl;
    std::cout << "Ali w: " << behaviors[1].weight << std::endl;
    std::cout << "Sep w: " << behaviors[2].weight << std::endl;*/
}
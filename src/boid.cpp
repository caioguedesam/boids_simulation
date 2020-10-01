#include "../include/boid.h"

Boid::Boid() {
    this->position = vec3(0, 0, 0);
    this->moveDirection = vec3(0, 0, 0);
    this->lastMoveDirection = vec3();
    this->moveSpeed = 0;
    this->color = vec4();
}

Boid::Boid(vec3 position, vec3 moveDirection, float moveSpeed, unsigned int id) {
    this->id = id;
    this->position = position;
    this->moveDirection = moveDirection;
    this->lastMoveDirection = vec3();
    this->moveSpeed = moveSpeed;
    this->maxRotationAngle = 5;
    this->color = vec4(1,1,1,1);

    this->size = vec2(10, 10);
    this->tipSize = 30;

    this->vertices = {
        -size.x, -size.y, 0,    //0
        size.x, -size.y, 0,     //1
        size.x, size.y, 0,      //2
        -size.x, size.y, 0,     //3
        0, 0, tipSize           //4
    };
    this->triangles = {
        0, 1, 2,
        0, 3, 2,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };
}

vec3 Boid::getPosition() { return position; }
vec3 Boid::getMoveDirection() { return moveDirection; }
void Boid::setMoveDirection(const vec3& dir) {
    lastMoveDirection = moveDirection;
    moveDirection = dir;
}

void Boid::update() {
    move();
    printStats();
}

void Boid::draw() {
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    faceMoveDirection();
    //glutSolidCube(10);

    glColor3f(color.x, color.y, color.z);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glDrawElements(GL_TRIANGLES, triangles.size(), GL_UNSIGNED_INT, &triangles[0]);

    glPopMatrix();
}

void Boid::drawMoveDir() {
    glColor3f(1,0,1);
    glBegin(GL_LINES);
    glVertex3f(position.x, position.y, position.z);
    vec3 norm = moveDirection.normalize();
    glVertex3f(position.x + norm.x * 30, position.y + norm.y * 30, position.z + norm.z * 30);
    glEnd();
}

void Boid::move() {
    position += moveDirection.normalize() * moveSpeed * deltaTime;
}

// TODO: FIX THIS to calculate rotation properly
void Boid::faceMoveDirection() {
    float angle = lastMoveDirection.angle(moveDirection);
    vec3 axis = cross(lastMoveDirection.normalize(), moveDirection.normalize());
    if(abs(angle) >= 1) {
        angle = clamp(angle, -maxRotationAngle, maxRotationAngle);
        glRotatef(angle, axis.x, axis.y, axis.z);
    }
}

void Boid::printStats() {
    //std::cout << "Boid " << id;
    //debugLog(position, ", position: ");
}
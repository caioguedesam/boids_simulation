#include "../include/boid.h"

Boid::Boid() {
    this->position = vec3(0, 0, 0);
    this->moveDirection = vec3(0, 0, 0);
    this->lastMoveDirection = vec3();
    this->moveSpeed = 0;
    this->color = vec4();
}

Boid::Boid(vec3 position, vec3 moveDirection, float moveSpeed) {
    this->position = position;
    this->moveDirection = moveDirection;
    this->lastMoveDirection = vec3();
    this->moveSpeed = moveSpeed;
    this->maxRotationAngle = 5;
    this->color = vec4(1,1,1,1);

    this->size = vec2(10, 10);
    this->tipSize = 30;
}

vec3 Boid::getPosition() { return position; }
vec3 Boid::getMoveDirection() { return moveDirection; }
void Boid::setMoveDirection(const vec3& dir) {
    lastMoveDirection = moveDirection;
    moveDirection = dir;
}

/*GLfloat* Boid::getVertices() {
    /*GLfloat vertices[] = {
        position.x + size.x, position.y + size.y, 0,
        position.x - size.x, position.y + size.y, 0,
        position.x + size.x, position.y - size.y, 0,
        position.x - size.x, position.y - size.y, 0,
        position.x, position.y, tipSize
    };
    GLfloat vertices[] = {
        size.x, size.y, 0,
        -size.x, size.y, 0,
        size.x, -size.y, 0,
        -size.x, -size.y, 0,
        0, 0, tipSize
    };
    return vertices;
}

GLfloat* Boid::getColors() {
    GLfloat colors[] = {
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1
    };
    return colors;
}*/

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
    //glRotatef(45, 1, 1, 0);
    faceMoveDirection();
    // Currently, boid is solid cube;
    glutSolidCube(10);

    /*GLfloat vertices[] = {
        size.x, size.y, 0,
        -size.x, size.y, 0,
        size.x, -size.y, 0,
        -size.x, -size.y, 0,
        0, 0, tipSize
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(3);
    glArrayElement(2);
    glEnd();*/
    glPopMatrix();
}

void Boid::drawMoveDir() {
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex3f(position.x, position.y, position.z);
    vec3 norm = moveDirection.normalize();
    //glVertex3f(position.x + norm.x * 30, position.y + norm.y * 30, position.z + norm.z * 30);
    glVertex3f(position.x + norm.x * 30, position.y + norm.y * 30, position.z);
    glEnd();
}

void Boid::move() {
    position += moveDirection.normalize() * moveSpeed * deltaTime;
}

void Boid::faceMoveDirection() {
    float angle = lastMoveDirection.angle(moveDirection);
    vec3 axis = cross(lastMoveDirection.normalize(), moveDirection.normalize());
    if(abs(angle) >= 1) {
        angle = clamp(angle, -maxRotationAngle, maxRotationAngle);
        glRotatef(angle, axis.x, axis.y, axis.z);
    }
}

void Boid::printStats() {
    //debugLog(moveDirection.normalize(), "MOVING WITH DIR: ");
}

void Boid::drawTriangle(int a, int b, int c) {
    glArrayElement(a);
    glArrayElement(b);
    glArrayElement(c);
}
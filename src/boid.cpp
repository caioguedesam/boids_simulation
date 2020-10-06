#include "../include/boid.h"

Boid::Boid() {
    this->position = vec3(0, 0, 0);
    this->moveDirection = vec3(0, 0, 0);
    this->lastMoveDirection = vec3();
    this->moveSpeed = 0;
    this->color = vec4();
}

Boid::Boid(vec3 position, vec3 moveDirection, float moveSpeed, Model* model, unsigned int id) {
    this->id = id;
    this->position = position;
    this->moveDirection = moveDirection;
    this->lastMoveDirection = vec3(0,0,1);
    this->moveSpeed = moveSpeed;
    this->color = vec4(1,1,1,1);

    this->model = model;
}

vec3 Boid::getPosition() { return position; }
vec3 Boid::getMoveDirection() { return moveDirection; }
void Boid::setMoveDirection(const vec3& dir) {
    lastMoveDirection = moveDirection;
    moveDirection = dir;
}

void Boid::update() {
    move();
}

void Boid::draw() {
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    faceMoveDirection();

    glColor3f(color.x, color.y, color.z);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &model->vertices[0]);
    glNormalPointer(GL_FLOAT, 0, &model->normals[0]);
    glDrawArrays(GL_TRIANGLES, 0, model->vertices.size()/3);
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

void Boid::faceMoveDirection() {
    vec3 forward = vec3(0,0,1);
    vec3 newForward = moveDirection.normalize();
    // Prevent errors in very small rotations (?)
    if((newForward-forward).magnitude2() < 0.05) {
        return;
    }

    float angle = rad2deg(acos(dot(forward, newForward)));
    vec3 axis = cross(forward, newForward).normalize();

    glRotatef(angle, axis.x, axis.y, axis.z);
}

// TODO: FIX THIS to calculate rotation properly with quaternions
/*void Boid::faceMoveDirection() {
    // Get rotation quaternion towards move direction (ERROR HERE)
    quat rot;
    rot = quat::rotationBetweenVectors(lastMoveDirection, moveDirection);
    /*quat rot = quat::angleAxis(deg2rad(lastAngle), vec3(1, 0, 0));

    // previous rotations
    rot = rot * lastRot;
    // apply quaternion rotations with rotation matrix multiplication
    std::vector<float> rotMatrix = rot.rotationMatrix();
    glMultMatrixf(&rotMatrix[0]);
    // store rotations
    lastRot = rot;
}*/
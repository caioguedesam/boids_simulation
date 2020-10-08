#include "../include/camera.h"

Camera::Camera() {}

Camera::Camera(CameraState state, std::vector<Boid*>* boids, Tower* tower) {
    this->state = state;
    this->boids = boids;
    this->tower = tower;
}

void Camera::setCamera() {
    switch(state) {
        case CameraState::TOWER:
            setTowerState();
            break;
        case CameraState::BEHIND:
            setBehindState();
            break;
        case CameraState::SIDE:
            setSideState();
            break;
        default:
            break;
    }
}

void Camera::setTowerState() {
    vec3 eyePos = tower->position + vec3(0, 1000, 0);
    vec3 lookPos = getBoidAvgPos();
    gluLookAt(eyePos.x, eyePos.y, eyePos.z, lookPos.x, lookPos.y, lookPos.z, 0, 1, 0);
}

void Camera::setBehindState() {
    vec3 offset = vec3(0, 0, -700);
    vec3 lookPos = getBoidAvgPos();
    vec3 eyePos = lookPos + offset;
    gluLookAt(eyePos.x, eyePos.y, eyePos.z, lookPos.x, lookPos.y, lookPos.z, 0, 1, 0);
}

void Camera::setSideState() {
    vec3 avgPos = getBoidAvgPos();
    vec3 avgMoveDir = getBoidAvgDir();
    vec3 up = vec3(0,1,0);
    vec3 moveDirCross = cross(avgMoveDir, up).normalize();
    float offset = 400;

    vec3 lookPos = avgPos;
    vec3 eyePos = lookPos + moveDirCross * offset;
    gluLookAt(eyePos.x, eyePos.y, eyePos.z, lookPos.x, lookPos.y, lookPos.z, 0, 1, 0);
}

void Camera::changeState(char key) {
    switch (key) {
        case '1':
            state = CameraState::TOWER;
            break;
        case '2':
            state = CameraState::BEHIND;
            break;
        case '3':
            state = CameraState::SIDE;
            break;
        default:
            break;
    }
}

vec3 Camera::getBoidAvgDir() {
    vec3 result = vec3(0,0,0);
    int count = 0;
    for(auto it = boids->begin(); it != boids->end(); it++) {
        result += (*it)->getMoveDirection();
        count++;
    }
    if(count > 0)
        result = result / count;
    return result;
}

vec3 Camera::getBoidAvgPos() {
    vec3 result = vec3(0,0,0);
    int count = 0;
    for(auto it = boids->begin(); it != boids->end(); it++) {
        result += (*it)->getPosition();
        count++;
    }
    if(count > 0)
        result = result / count;
    return result;
}
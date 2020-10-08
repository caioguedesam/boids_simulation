#pragma once
#include "../include/vec.h"
#include "../include/tower.h"
#include <vector>
#include "../include/boid.h"
#include <iostream>

enum class CameraState { TOWER, BEHIND, SIDE };

class Camera {
public:
    CameraState state;
    std::vector<Boid*>* boids;
    Tower* tower;

    Camera();
    Camera(CameraState state, std::vector<Boid*>* boids, Tower* tower);

    void setCamera();
    void setTowerState();
    void setBehindState();
    void setSideState();

    vec3 getBoidAvgPos();

    void changeState(char input);
};
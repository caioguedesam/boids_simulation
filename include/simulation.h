#pragma once
#include "../include/boid.h"
#include <vector>

class Simulation {
private:
    std::vector<Boid*> boidList;
public:
    Simulation();
    Simulation(const int& boidCount);
    ~Simulation();

    void update();
    void draw();
};
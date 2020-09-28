#pragma once
#include "../include/boid.h"
#include "../include/boid_behaviors.h"
#include <random>
#include <vector>

class Simulation {
private:
    std::vector<Boid*> boidList;
    std::vector<Behavior*> behaviorList;

    float radius;
    float closeRadius;
public:
    Simulation();
    Simulation(const int& boidCount);
    ~Simulation();

    void update();
    void draw();

    void calculateAllBoidDirections();
    void drawBehaviorLine(vec3 dir, vec4 color, Boid& boid);
    vec3 getRandomBoidPos();
};
#pragma once
#include "../include/boid.h"
#include "../include/center_boid.h"
#include "../include/move_input.h"
#include "../include/boid_behaviors.h"
#include "../include/model.h"
#include <random>
#include <vector>

class Simulation {
private:
    Model* boidModel;

    CenterBoid* centerBoid;
    std::vector<Boid*> boidList;
    std::vector<Behavior*> behaviorList;

    MoveInput centerBoidInput;

    float radius;
    float closeRadius;
public:
    bool debugDraw;
    Simulation();
    Simulation(const int& boidCount);
    ~Simulation();

    void getInputDown(unsigned char key);
    void getInputUp(unsigned char key);

    void update();
    void draw();

    void calculateAllBoidDirections();
    void drawBehaviorLine(vec3 dir, vec4 color, Boid& boid);
    vec3 getRandomBoidPos();
    vec3 getRandomBoidMoveDir();
    vec3 getCenterBoidPos();
    vec3 getCenterBoidDir();
};
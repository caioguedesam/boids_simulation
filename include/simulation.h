#pragma once
#include "../include/boid.h"
#include "../include/center_boid.h"
#include "../include/move_input.h"
#include "../include/boid_behaviors.h"
#include "../include/model.h"
#include "../include/ground.h"
#include "../include/tower.h"
#include "../include/camera.h"
#include <random>
#include <vector>

enum class SimulationState { PAUSED, PLAYING };

class Simulation {
private:
    SimulationState state;
    bool pauseButtonDown;
    bool pauseAfterUpdate;

    Model* boidModel;
    Camera camera;

    Ground* ground;
    Tower* tower;

    CenterBoid* centerBoid;
    std::vector<Boid*> boidList;
    std::vector<Behavior*> behaviorList;

    MoveInput centerBoidInput;

    float radius;
    float closeRadius;
public:
    Simulation();
    Simulation(const int& boidCount);
    ~Simulation();

    void getInputDown(unsigned char key);
    void getInputUp(unsigned char key);
    void getMouseInput(int button, int buttonState);

    void update();
    void draw();
    void setCamera();

    void play();
    void pause();
    void displayStats();

    void addBoid();
    void removeBoid();
    void calculateAllBoidDirections();
    void drawBehaviorLine(vec3 dir, vec4 color, Boid& boid);
    vec3 getRandomBoidPos();
    vec3 getRandomBoidMoveDir();
    vec3 getRandomBoidPosNearCenter();
    vec3 getAvgBoidPos();
    vec3 getCenterBoidPos();
    vec3 getCenterBoidDir();
};
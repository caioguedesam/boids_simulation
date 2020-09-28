#include "../include/simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(const int& boidCount) {
    radius = 100;
    closeRadius = 10;

    boidList = std::vector<Boid*>();
    for(int i = 0; i < boidCount; i++) {
        //vec3 pos = vec3(0 + i * 10,0 + i * 10,0);
        vec3 pos = getRandomBoidPos();
        vec3 moveDir = vec3(0,1,0);
        float moveSpeed = 50.0;
        this->boidList.push_back(new Boid(pos, moveDir, moveSpeed));
    }

    behaviorList = std::vector<Behavior*>();
    behaviorList.push_back(new Cohesion(9, radius));
    behaviorList.push_back(new Alignment(8, radius));
    behaviorList.push_back(new Separation(12, closeRadius));
}

Simulation::~Simulation() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); ) {
        delete (*it);
        it = boidList.erase(it);
    }

    for(std::vector<Behavior*>::iterator it = behaviorList.begin(); it != behaviorList.end(); ) {
        delete (*it);
        it = behaviorList.erase(it);
    }
}

void Simulation::update() {
    calculateAllBoidDirections();

    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->update();
    }
}

void Simulation::draw() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->draw();
    }
}

void Simulation::calculateAllBoidDirections() {
    for(auto it_boid = boidList.begin(); it_boid != boidList.end(); it_boid++) {
        vec3 moveDirection = vec3();

        for(auto it_bhv = behaviorList.begin(); it_bhv != behaviorList.end(); it_bhv++) {
            moveDirection += (*it_bhv)->calculateMoveDirection(**it_boid, boidList) * (*it_bhv)->weight;
            if(isnan(moveDirection.x) || isnan(moveDirection.y) || isnan(moveDirection.z)) {
                std::cout << "FOUND NAN" << std::endl;
                exit(0);
            }
        }

        (*it_boid)->setMoveDirection(moveDirection);
    }
}

vec3 Simulation::getRandomBoidPos() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-500, 500);

    return vec3(distr(gen), distr(gen), 0);

}
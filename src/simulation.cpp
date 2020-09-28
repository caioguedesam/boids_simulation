#include "../include/simulation.h"

Simulation::Simulation() {

}

Simulation::Simulation(const int& boidCount) {
    for(int i = 0; i < boidCount; i++) {
        vec3 pos = vec3(0,0,0);
        vec3 moveDir = vec3(1,1,0);
        float moveSpeed = 50.0;
        this->boidList.push_back(new Boid(pos, moveDir, moveSpeed));
    }
}

Simulation::~Simulation() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); ) {
        delete (*it);
        it = boidList.erase(it);
    }
}

void Simulation::update() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->update();
    }
}

void Simulation::draw() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->draw();
    }
}
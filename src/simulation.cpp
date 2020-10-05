#include "../include/simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(const int& boidCount) {
    debugDraw = false;

    radius = 100;
    closeRadius = 30;

    centerBoid = new CenterBoid(vec3(0,0,0), vec3(0,0,1), 50, vec4(0,1,0,1), 0);
    centerBoidInput = MoveInput();

    boidList = std::vector<Boid*>();
    boidList.push_back(centerBoid);
    for(int i = 0; i < boidCount; i++) {
        vec3 pos = getRandomBoidPos();
        vec3 moveDir = getRandomBoidMoveDir();
        float moveSpeed = 50.0;
        this->boidList.push_back(new Boid(pos, moveDir, moveSpeed, i+1));
    }

    behaviorList = std::vector<Behavior*>();
    behaviorList.push_back(new Cohesion(9, radius));
    behaviorList.push_back(new Alignment(4, radius));
    behaviorList.push_back(new Separation(12, closeRadius));
    behaviorList.push_back(new Follow(6, centerBoid));
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

void Simulation::getInputDown(unsigned char key) {
    centerBoidInput.getInputDown(key);
}

void Simulation::getInputUp(unsigned char key) {
    centerBoidInput.getInputUp(key);
}

void Simulation::update() {
    centerBoid->getInput(centerBoidInput);
    calculateAllBoidDirections();

    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->update();
    }
}

void Simulation::draw() {
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->draw();
        //(*it)->drawMoveDir();
    }
}

void Simulation::calculateAllBoidDirections() {
    // Calculates for all but first list element, which is center boid
    for(auto it_boid = boidList.begin() + 1; it_boid != boidList.end(); it_boid++) {
        vec3 moveDirection = vec3();

        for(auto it_bhv = behaviorList.begin(); it_bhv != behaviorList.end(); it_bhv++) {
            moveDirection += (*it_bhv)->calculateMoveDirection(**it_boid, boidList) * (*it_bhv)->weight;
            if(isnan(moveDirection.x) || isnan(moveDirection.y) || isnan(moveDirection.z)) {
                std::cout << "FOUND NAN" << std::endl;
                exit(0);
            }
        }

        (*it_boid)->setMoveDirection(vec3Lerp((*it_boid)->getMoveDirection(), moveDirection, 5 * deltaTime));
    }
}

vec3 Simulation::getCenterBoidPos() {
    if(centerBoid == nullptr) return vec3();

    return centerBoid->getPosition();
}

vec3 Simulation::getCenterBoidDir() {
    if(centerBoid == nullptr) return vec3();

    return centerBoid->getMoveDirection();
}

vec3 Simulation::getRandomBoidPos() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-500, 500);

    return vec3(distr(gen), distr(gen), 0);
}

vec3 Simulation::getRandomBoidMoveDir() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-500, 500);

    return vec3(distr(gen), distr(gen), distr(gen)).normalize();
}
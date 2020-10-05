#include "../include/simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(const int& boidCount) {
    debugDraw = false;

    radius = 100;
    closeRadius = 30;

    centerBoid = new CenterBoid(vec3(0,0,0), vec3(0,0,1), 50, vec4(0,1,0,1), 0);
    centerBoidInput = MoveInput();

    boidList = std::vector<Boid*>();
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

    delete centerBoid;
}

void Simulation::getInputDown(unsigned char key) {
    if(key == 'w' && !centerBoidInput.upHold) {
        centerBoidInput.upHold = true;
        centerBoidInput.input.y = 1;
    }
    else if(key == 's' && !centerBoidInput.downHold) {
        centerBoidInput.downHold = true;
        centerBoidInput.input.y = -1;
    }
    else if(key == 'd' && !centerBoidInput.rightHold) {
        centerBoidInput.rightHold = true;
        centerBoidInput.input.x = 1;
    }
    else if(key == 'a' && !centerBoidInput.leftHold) {
        centerBoidInput.leftHold = true;
        centerBoidInput.input.x = -1;
    }
    else if(key == 'l' && !centerBoidInput.turnRightHold) {
        centerBoidInput.turnRightHold = true;
        centerBoidInput.input.z = 1;
    }
    else if(key == 'j' && !centerBoidInput.turnLeftHold) {
        centerBoidInput.turnLeftHold = true;
        centerBoidInput.input.z = -1;
    }
}

void Simulation::getInputUp(unsigned char key) {
    if(key == 'w' && centerBoidInput.upHold) {
        centerBoidInput.upHold = false;
        centerBoidInput.input.y = 0;
    }
    else if(key == 's' && centerBoidInput.downHold) {
        centerBoidInput.downHold = false;
        centerBoidInput.input.y = 0;
    }
    else if(key == 'd' && centerBoidInput.rightHold) {
        centerBoidInput.rightHold = false;
        centerBoidInput.input.x = 0;
    }
    else if(key == 'a' && centerBoidInput.leftHold) {
        centerBoidInput.leftHold = false;
        centerBoidInput.input.x = 0;
    }
    else if(key == 'l' && centerBoidInput.turnRightHold) {
        centerBoidInput.turnRightHold = false;
        centerBoidInput.input.z = 0;
    }
    else if(key == 'j' && centerBoidInput.turnLeftHold) {
        centerBoidInput.turnLeftHold = false;
        centerBoidInput.input.z = 0;
    }
}

void Simulation::update() {
    centerBoid->getInput(centerBoidInput);
    calculateAllBoidDirections();

    centerBoid->update();
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->update();
    }

    //centerBoid->print();
}

void Simulation::draw() {
    centerBoid->draw();
    centerBoid->drawMoveDir();
    centerBoid->drawRightVector();
    centerBoid->drawUpVector();
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->draw();
        (*it)->drawMoveDir();
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
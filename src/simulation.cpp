#include "../include/simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(const int& boidCount) {
    state = SimulationState::PLAYING;
    pauseButtonDown = false;
    pauseAfterUpdate = false;

    radius = 100;
    closeRadius = 50;

    std::vector<float> vertices, uvs, normals;
    loadOBJ("assets/models/boidmodel.obj", vertices, uvs, normals);
    boidModel = new Model(vertices, uvs, normals);

    vec3 groundPos = vec3(1000, -500, 1000);

    ground = new Ground(groundPos, vec2(5000, 5000));
    tower = new Tower(groundPos, vec3(500, 700, 0));

    centerBoid = new CenterBoid(vec3(0,0,0), vec3(0,0,1), 200, boidModel, 0);
    centerBoidInput = MoveInput();

    boidList = std::vector<Boid*>();
    boidList.push_back(centerBoid);
    for(int i = 0; i < boidCount; i++) {
        vec3 pos = getRandomBoidPos();
        vec3 moveDir = getRandomBoidMoveDir();
        float moveSpeed = 200.0;
        this->boidList.push_back(new Boid(pos, moveDir, moveSpeed, boidModel, i+1));
    }

    behaviorList = std::vector<Behavior*>();
    behaviorList.push_back(new Cohesion(9, radius));
    behaviorList.push_back(new Alignment(4, radius));
    behaviorList.push_back(new Separation(24, closeRadius));
    behaviorList.push_back(new Follow(6, centerBoid));

    camera = Camera(CameraState::BEHIND, &boidList, tower);
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

    delete boidModel;
    delete ground;
    delete tower;
}

void Simulation::getInputDown(unsigned char key) {
    if(key == '+') {
        addBoid();
        return;
    }
    else if(key == '-') {
        removeBoid();
        return;
    }

    camera.changeState(key);
    centerBoidInput.getInputDown(key);
}

void Simulation::getInputUp(unsigned char key) {
    centerBoidInput.getInputUp(key);
}

void Simulation::getMouseInput(int button, int buttonState) {
    switch(button) {
        case GLUT_LEFT_BUTTON:
            if(buttonState == GLUT_DOWN) {
                if(state == SimulationState::PAUSED)
                    play();
                else
                    pause();
                pauseAfterUpdate = false;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(buttonState == GLUT_DOWN) {
                if(state == SimulationState::PAUSED)
                    play();
                else
                    pause();
                pauseAfterUpdate = true;
                displayStats();
            }
            break;
        default:
            break;
    }
}

void Simulation::update() {
    if(state == SimulationState::PLAYING) {
        centerBoid->getInput(centerBoidInput);
        calculateAllBoidDirections();

        for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
            (*it)->update();
        }

        if(pauseAfterUpdate)
            pause();
    }
}

void Simulation::draw() {
    ground->draw();
    tower->draw();
    for(std::vector<Boid*>::iterator it = boidList.begin(); it != boidList.end(); it++) {
        (*it)->draw();
        //(*it)->drawMoveDir();
    }
}

void Simulation::setCamera() {
    camera.setCamera();
}

void Simulation::play() {
    state = SimulationState::PLAYING;
}

void Simulation::pause() {
    state = SimulationState::PAUSED;
}

void Simulation::displayStats() {
    std::cout << "Boid simulation stats on time: " << elapsedTime << std::endl;
    std::cout << "Center boid:" << std::endl;
    debugLog(getCenterBoidPos(), "      Position: ");
    debugLog(getCenterBoidDir(), "      Move Direction: ");
    std::cout << "Other boids:" << std::endl;
    for(auto it = boidList.begin(); it != boidList.end(); it++) {
        std::cout << "  Boid #" << it - boidList.begin() << std::endl;
        debugLog((*it)->getPosition(), "        Position: ");
        debugLog((*it)->getMoveDirection(), "       Move Direction: ");
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

vec3 Simulation::getAvgBoidPos() {
    vec3 result = vec3(0,0,0);
    int count = 0;
    for(auto it = boidList.begin(); it != boidList.end(); it++) {
        result += (*it)->getPosition();
        count++;
    }
    if(count > 0)
        result = result / count;
    return result;
}

vec3 Simulation::getRandomBoidPos() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-500, 500);

    return vec3(distr(gen), distr(gen), distr(gen));
}

vec3 Simulation::getRandomBoidPosNearCenter() {
    vec3 center = getAvgBoidPos();
    float maxOffset = 200;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-maxOffset, maxOffset);

    return vec3(center.x + distr(gen), center.y + distr(gen), center.z + distr(gen));
}

vec3 Simulation::getRandomBoidMoveDir() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-500, 500);

    return vec3(distr(gen), distr(gen), distr(gen)).normalize();
}

void Simulation::addBoid() {
    vec3 pos = getRandomBoidPosNearCenter();
    vec3 moveDir = getRandomBoidMoveDir();
    float moveSpeed = 200.0;
    this->boidList.push_back(new Boid(pos, moveDir, moveSpeed, boidModel));
}

void Simulation::removeBoid() {
    if(boidList.size() > 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        // Get random index from 1 (first non center boid) to last boid index
        std::uniform_int_distribution<> distr(1, boidList.size() - 1);
        int randomIndex = distr(gen);
        auto it = boidList.begin() + randomIndex;

        delete (*it);
        boidList.erase(it);
    }
}


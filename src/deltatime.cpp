#include "../include/deltatime.h"

unsigned int elapsedTime = 0;
float deltaTime = 0.0;

void updateDeltaTime() {
    int time = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = (time - elapsedTime)/1000.0;
    elapsedTime = time;
}
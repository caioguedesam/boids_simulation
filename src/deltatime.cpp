#include "../include/deltatime.h"

unsigned int lastTime = 0;
float deltaTime = 0.0;

void updateDeltaTime() {
    int time = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = (time - lastTime)/1000.0;
    lastTime = time;
}
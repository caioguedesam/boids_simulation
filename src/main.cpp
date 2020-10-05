#include <GL/freeglut.h>
#include "../include/simulation.h"

vec2 windowSize = vec2(1280, 720);
float spin = 0;
Simulation simulation = Simulation(200);

// Change this later to support different cam modes. Maybe camera class?
void setCamera() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,100,-300,0,0,0,0,1,0);
    /*vec3 lookPos = simulation.getCenterBoidPos();
    vec3 eye = lookPos + simulation.getCenterBoidDir() * 200;
    gluLookAt(eye.x, eye.y, eye.z, lookPos.x, lookPos.y, lookPos.z, 0, 1, 0);*/
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
    setCamera();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    simulation.draw();
    glutSwapBuffers();
    // Testing camera follow
    setCamera();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-windowSize.x/2, windowSize.x/2, -windowSize.y/2, windowSize.y/2, -1000.0, 1000.0);
    gluPerspective(70, windowSize.x/windowSize.y, 0, 1000);
	setCamera();
}

void inputDown(unsigned char key, int x, int y) {
    simulation.getInputDown(key);
}

void inputUp(unsigned char key, int x, int y) {
    simulation.getInputUp(key);
}

void idle() {
    updateDeltaTime();
    simulation.update();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowSize.x)/2, (glutGet(GLUT_SCREEN_HEIGHT) - windowSize.y)/2);
	glutCreateWindow("Boids");
	glutSetCursor(GLUT_CURSOR_NONE);

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(inputDown);
    glutKeyboardUpFunc(inputUp);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}

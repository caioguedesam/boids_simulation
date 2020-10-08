#include <GL/freeglut.h>
#include "../include/simulation.h"
#include "../include/obj_loader.h"

vec2 windowSize = vec2(1280, 720);
Simulation simulation = Simulation(100);

void setLight() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    float lightAmbient[] = {0.15, 0.15, 0.15, 1.0};
    float lightDiffuse[] = {1.0, 1.0, 1.0, 1.0};
    float lightSpecular[] = {1.0, 1.0, 1.0, 1.0};
    float lightPosition[] = {-1.0, 1.0, 1.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPopMatrix();
}

void setCamera() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    simulation.setCamera();
    setLight();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
    setCamera();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    simulation.draw();
    glutSwapBuffers();
    setCamera();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(70, windowSize.x/windowSize.y, 50, 5000);
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

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
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

#include <GL/freeglut.h>
#include "../include/simulation.h"

vec2 windowSize = vec2(1280, 720);

Simulation simulation = Simulation(100);

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	simulation.draw();
	glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-windowSize.x/2, windowSize.x/2, -windowSize.y/2, windowSize.y/2, -1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}

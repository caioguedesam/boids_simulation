#include <GL/freeglut.h>
#include "../include/simulation.h"

vec2 windowSize = vec2(1280, 720);
float spin = 0;
Simulation simulation = Simulation(200);

/*void drawTriangle(vec3 a, vec3 b, vec3 c) {
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(c.x, c.y, c.z);
}

void drawPyramid(vec3* vertices) {
    drawTriangle(vertices[0], vertices[1], vertices[2]);
    drawTriangle(vertices[0], vertices[3], vertices[2]);
    drawTriangle(vertices[0], vertices[1], vertices[4]);
    drawTriangle(vertices[1], vertices[2], vertices[4]);
    drawTriangle(vertices[2], vertices[3], vertices[4]);
    drawTriangle(vertices[3], vertices[0], vertices[4]);
}

void drawLine(vec3 a, vec3 b) {
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(b.x, b.y, b.z);
}

void drawWires(vec3* vertices) {
    drawLine(vertices[0], vertices[1]);
    drawLine(vertices[1], vertices[2]);
    drawLine(vertices[2], vertices[3]);
    drawLine(vertices[3], vertices[0]);
    drawLine(vertices[0], vertices[4]);
    drawLine(vertices[1], vertices[4]);
    drawLine(vertices[2], vertices[4]);
    drawLine(vertices[3], vertices[4]);
}

void drawShape(float x, float y, float z) {
    glPushMatrix();

    spin += 30 * deltaTime;
    if(spin >= 360) spin = 0;
    glTranslatef(x, y, z);
    glRotatef(spin, 0, 1, 0);

    vec2 size = vec2(10, 10);
    GLfloat tipSize = 30;

    vec3 vertices[] = {
        vec3(size.x, size.y, 0),
        vec3(-size.x, size.y, 0),
        vec3(-size.x, -size.y, 0),
        vec3(size.x, -size.y, 0),
        vec3(0, 0, tipSize)
    };

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    drawPyramid(vertices);
    glEnd();

    glColor3f(1,0,1);
    glBegin(GL_LINES);
    drawWires(vertices);
    glEnd();
    
    glPopMatrix();
}

void drawShape2(float x, float y, float z) {
    glPushMatrix();

    spin += 30 * deltaTime;
    if(spin >= 360) spin = 0;
    glTranslatef(x, y, z);
    glRotatef(spin, 0, 1, 0);

    vec2 size = vec2(10, 10);
    float tipSize = 30;
    std::vector<float> vertices = {
        -size.x, -size.y, 0,    //0
        size.x, -size.y, 0,     //1
        size.x, size.y, 0,      //2
        -size.x, size.y, 0,     //3
        0, 0, tipSize           //4
    };
    std::vector<int> triangles = {
        0, 1, 2,
        0, 3, 2,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glDrawElements(GL_TRIANGLES, triangles.size(), GL_UNSIGNED_INT, &triangles[0]);

    glPopMatrix();
}*/

// Change this later to support different cam modes. Maybe camera class?
void setCamera() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,100,-300,0,0,0,0,1,0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
    setCamera();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    simulation.draw();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-windowSize.x/2, windowSize.x/2, -windowSize.y/2, windowSize.y/2, -1000.0, 1000.0);
    gluPerspective(70, windowSize.x/windowSize.y, 0, 1000);
	setCamera();
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

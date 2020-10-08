#include "../include/tower.h"

Tower::Tower() {}

Tower::Tower(vec3 position, vec3 scale) {
    this->position = position;
    this->scale = scale;
}

void Tower::setMaterial() {
    float matAmbient[] = {0.4, 0.4, 0.4, 1.0};
    float matDiffuse[] = {0.7, 0.7, 1, 1.0};
    float matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    float lowShininess[] = { 5.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, lowShininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
}

void Tower::draw() {
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(-90, 1, 0, 0);

    setMaterial();
    glutSolidCone(scale.x, scale.y, 50, 50);

    glPopMatrix();
}
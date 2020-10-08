#include "../include/ground.h"

Ground::Ground() {}

Ground::Ground(vec3 position, vec2 size) {
    this->position = position;
    this->size = size;
}

void Ground::setMaterial() {
    float matAmbDiff[] = {0.1, 0.1, 0.1, 1.0};
    float matSpecular[] = { 0.2, 0.2, 0.2, 1.0 };
    float lowShininess[] = { 5.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, lowShininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbDiff);
}

void Ground::draw() {
    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);

    std::vector<float> vertices = {
        // First triangle
        -size.x, 0, -size.y,
        size.x, 0, -size.y,
        size.x, 0, size.y,
        // Second triangle
        -size.x, 0, -size.y,
        size.x, 0, size.y,
        -size.x, 0, size.y
    };
    std::vector<float> normals = {
        0,1,0,
        0,1,0,
        0,1,0,
        0,1,0,
        0,1,0,
        0,1,0
    };

    setMaterial();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    glNormalPointer(GL_FLOAT, 0, &normals[0]);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size()/3);
    glPopMatrix();
}

bool Ground::isNearBoid(Boid* boid, const float& radius) {
    float dist2 = (boid->getPosition() - position).magnitude2();
    return (dist2 <= radius * radius);
}
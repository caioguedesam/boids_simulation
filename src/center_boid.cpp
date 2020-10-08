#include "../include/center_boid.h"

CenterBoid::CenterBoid(vec3 position, vec3 moveDirection, float moveSpeed, Model* model, unsigned int id)
    : Boid(position, moveDirection, moveSpeed, model, id) {
    this->color = vec4(0,1,0,1);
    this->angularSpeed = 200.0f;
}

// There are problems here, maybe implementing quaternions properly will fix them...
// They're reoughly the same as the boid rotation problems
void CenterBoid::getInput(MoveInput input) {
    vec3 forward = moveDirection.normalize();
    vec3 u = (input.input.z < 0) ? vec3(0,1,0) : vec3(0, -1, 0);
    vec3 right = cross(u, forward).normalize();
    vec3 up = cross(forward, right);

    float angleX = deg2rad(input.input.x * angularSpeed * deltaTime);
    float angleY = deg2rad(input.input.y * angularSpeed * deltaTime);
    std::vector<float> rotMatrixX = rotationMatrix(angleX, up);
    std::vector<float> rotMatrixY = rotationMatrix(angleY, right);
    vec3 newMoveDir = (input.upHold || input.downHold) ? moveDirection.rotate(rotMatrixY) : moveDirection.rotate(rotMatrixX);
    setMoveDirection(newMoveDir);
}

vec3 CenterBoid::rotateMoveDirection(quat rotationQuat) {
    vec4 moveDir = vec4(moveDirection.x, moveDirection.y, moveDirection.z, 0).normalize();
    std::vector<float> rot = rotationQuat.rotationMatrix();
    vec4 result = vec4(
        rot[0]*moveDir.x+rot[1]*moveDir.y+rot[2]*moveDir.z+rot[3]*moveDir.w,
        rot[4]*moveDir.x+rot[5]*moveDir.y+rot[6]*moveDir.z+rot[7]*moveDir.w,
        rot[8]*moveDir.x+rot[9]*moveDir.y+rot[10]*moveDir.z+rot[11]*moveDir.w,
        rot[12]*moveDir.x+rot[13]*moveDir.y+rot[14]*moveDir.z+rot[15]*moveDir.w
    );
    return vec3(moveDir.x, moveDir.y, moveDir.z);
}

void CenterBoid::print() {
    debugLog(moveDirection, "center boid move dir: ");
}

void CenterBoid::setMaterial() {
    float matAmbDiff[] = {0.117, 0.341, 0.172, 1.0};
    float matSpecular[] = { 0.109, 0.831, 0.109, 1.0 };
    float lowShininess[] = { 5.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, lowShininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbDiff);
}

void CenterBoid::drawRightVector() {
    vec3 forward = moveDirection.normalize();
    vec3 u = vec3(0,1,0);
    vec3 right = cross(u, forward).normalize();
    vec3 up = cross(forward, right);

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex3f(position.x, position.y, position.z);
    vec3 norm = right.normalize();
    glVertex3f(position.x + norm.x * 30, position.y + norm.y * 30, position.z + norm.z * 30);
    glEnd();
}

void CenterBoid::drawUpVector() {
    vec3 forward = moveDirection.normalize();
    vec3 u = vec3(0,1,0);
    vec3 right = cross(u, forward).normalize();
    vec3 up = cross(forward, right);

    glColor3f(0,1,1);
    glBegin(GL_LINES);
    glVertex3f(position.x, position.y, position.z);
    vec3 norm = up.normalize();
    glVertex3f(position.x + norm.x * 30, position.y + norm.y * 30, position.z + norm.z * 30);
    glEnd();
}
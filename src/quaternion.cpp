#include "../include/quaternion.h"

quat::quat() {
    this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	this->w = 1.0;
}

quat::quat(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

quat quat::operator*(const quat& rhs) {
    float w = this->w * rhs.w - this->x * rhs.x - this->z * rhs.z - this->z * rhs.z;
    float x = this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y;
    float y = this->w * rhs.y - this->x * rhs.z + this->y * rhs.w + this->z * rhs.x;
    float z = this->w * rhs.z + this->x * rhs.y - this->y * rhs.x - this->z * rhs.w;
    return quat(x, y, z, w);
}

quat quat::conjugate() {
    return quat(-x, -y, -z, w);
}

quat quat::normalize() {
    float n = 1.0f / sqrt(x*x + y*y + z*z + w*w);
    return quat(x*n, y*n, z*n, w*n);
}

std::vector<float> quat::toMatrix() {
    std::vector<float> matrix = {
        w*w + x*x - y*y - z*z, 2*x*y - 2*w*z, 2*x*z + 2*w*y, 0,
        2*x*y + 2*w*z, w*w - x*x + y*y - z*z, 2*y*z - 2*w*x, 0,
        2*x*z - 2*w*y, 2*y*z + 2*w*x, w*w - x*x - y*y + z*z, 0,
        0, 0, 0, 1
    };
    return matrix;
}

std::vector<float> quat::rotationMatrix() {
    quat q = this->normalize();
    float qi = x, qj = y, qk = z, qr = w;
    // From wikipedia quaternion page
    std::vector<float> matrix = {
        1 - (2*qj*qj + 2*qk*qk), 2*qi*qj - 2*qk*qr, 2*qi*qk + 2*qj*qr, 0,
        2*qi*qj + 2*qk*qr, 1 - (2*qi*qi + 2*qk*qk), 2*qj*qk - 2*qi*qr, 0,
        2*qi*qk - 2*qj*qr, 2*qj*qk + 2*qi*qr, 1 - (2*qi*qi + 2*qj*qj), 0,
        0, 0, 0, 1
    };
    return matrix;
}

quat quat::identity() {
    return quat(0,0,0,1);
}

quat quat::angleAxis(float angle, vec3 axis) {
    float x = axis.x * sin(angle/2);
    float y = axis.y * sin(angle/2);
    float z = axis.z * sin(angle/2);
    float w = cos(angle/2);
    return quat(x,y,z,w).normalize();
}

void quat::print() {
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << ", w: " << w << std::endl;
}
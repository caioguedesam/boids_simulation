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

void quat::identity() {
    this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	this->w = 1.0;
}
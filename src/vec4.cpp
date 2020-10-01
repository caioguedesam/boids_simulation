#include "../include/vec4.h"

vec4::vec4() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	this->w = 0.0;
}

vec4::vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float vec4::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

vec4 vec4::normalize() {
	float magnitude = this->magnitude();
	if(magnitude == 0) return (*this);
	return vec4(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

float vec4::sqrDist(const vec4& rhs) {
	return pow(this->x - rhs.x, 2) + pow(this->y - rhs.y, 2) + pow(this->z - rhs.z, 2) + pow(this->w - rhs.w, 2);
}

vec4 vec4::operator+(const vec4& rhs) {
	vec4 result = vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
	return result;
}

vec4 vec4::operator-(const vec4& rhs) {
	vec4 result = vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
	return result;
}

vec4 vec4::operator-() {
	return vec4(-this->x, -this->y, -this->z, -this->w);
}

vec4 vec4::operator*(const vec4& rhs) {
	vec4 result = vec4(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w * rhs.w);
	return result;
}

vec4 vec4::operator*(const float& rhs) {
	return vec4(this->x * rhs, this->y * rhs, this->z * rhs, this->w * rhs);
}

vec4 vec4::operator+=(const vec4& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
	return *this;
}

vec4 vec4::operator/(const float& rhs) {
	return vec4(this->x/rhs, this->y/rhs, this->z/rhs, this->w/rhs);
}

vec4 vec4::operator/=(const float& rhs) {
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	this->w /= rhs;
	return *this;
}

vec4 vec4::operator/(const vec4& rhs) {
	return vec4(this->x/rhs.x, this->y/rhs.y, this->z/rhs.z, this->w/rhs.w);
}

vec4 vec4::operator/=(const vec4& rhs) {
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	this->w /= rhs.w;
	return *this;
}
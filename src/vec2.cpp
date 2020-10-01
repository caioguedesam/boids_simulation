#include "../include/vec2.h"

vec2::vec2() {
	this->x = 0.0;
	this->y = 0.0;
}

vec2::vec2(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
}

float vec2::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2));
}

vec2 vec2::normalize() {
	float magnitude = this->magnitude();
	if(magnitude == 0) return (*this);
	return vec2(x / magnitude, y / magnitude);
}

float vec2::sqrDist(const vec2& rhs) {
	return pow(this->x - rhs.x, 2) + pow(this->y - rhs.y, 2);
}

// rotates counter-clockwise
vec2 vec2::rotate(float angle) {
	float rad = angle * (PI / 180.0f);
	float cosine = cos(rad);
	float sine = sin(rad);

	return vec2(cosine * x - sine * y, sine * x + cosine * y);
}

vec2 vec2::operator+(const vec2& rhs) {
	vec2 result = vec2(this->x + rhs.x, this->y + rhs.y);
	return result;
}

vec2 vec2::operator-(const vec2& rhs) {
	vec2 result = vec2(this->x - rhs.x, this->y - rhs.y);
	return result;
}

vec2 vec2::operator-() {
	return vec2(-this->x, -this->y);
}

vec2 vec2::operator*(const vec2& rhs) {
	vec2 result = vec2(this->x * rhs.x, this->y * rhs.y);
	return result;
}

vec2 vec2::operator*(const float& rhs) {
	return vec2(this->x * rhs, this->y * rhs);
}

vec2 vec2::operator+=(const vec2& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

vec2 vec2::operator/(const float& rhs) {
	return vec2(this->x/rhs, this->y/rhs);
}

vec2 vec2::operator/=(const float& rhs) {
	this->x /= rhs;
	this->y /= rhs;
	return *this;
}

vec2 vec2::operator/(const vec2& rhs) {
	return vec2(this->x/rhs.x, this->y/rhs.y);
}

vec2 vec2::operator/=(const vec2& rhs) {
	this->x /= rhs.x;
	this->y /= rhs.y;
	return *this;
}
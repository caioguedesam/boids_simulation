#include "../include/vec3.h"

vec3::vec3() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

vec3::vec3(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float vec3::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float vec3::magnitude2() {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

vec3 vec3::normalize() {
	float magnitude = this->magnitude();
	if(magnitude == 0) return (*this);
	return vec3(x / magnitude, y / magnitude, z / magnitude);
}

float vec3::sqrDist(const vec3& rhs) {
	return pow(this->x - rhs.x, 2) + pow(this->y - rhs.y, 2) + pow(this->z - rhs.z, 2);
}

float vec3::angle(vec3& rhs) {
	vec3 a = this->normalize();
	vec3 b = rhs.normalize();
	return rad2deg(acos(dot(a,b)));
}

/*vec3 vec3::rotate(quat& q) {
	quat pure = quat(this->x, this->y, this->z, 0);
	quat qConj = q.conjugate();
	quat result = (q * pure) * qConj;
	return vec3(result.x, result.y, result.z);
}*/

vec3 vec3::operator+(const vec3& rhs) {
	vec3 result = vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	return result;
}

vec3 vec3::operator-(const vec3& rhs) {
	vec3 result = vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	return result;
}

vec3 vec3::operator-() {
	return vec3(-this->x, -this->y, -this->z);
}

vec3 vec3::operator*(const vec3& rhs) {
	vec3 result = vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
	return result;
}

vec3 vec3::operator*(const float& rhs) {
	return vec3(this->x * rhs, this->y * rhs, this->z * rhs);
}

/*quat vec3::operator*(const quat& rhs) {
	quat pure = quat(this->x, this->y, this->z, 0);
	return pure * rhs;
}*/

vec3 vec3::operator+=(const vec3 &rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

vec3 vec3::operator/(const float& rhs) {
	return vec3(this->x/rhs, this->y/rhs, this->z/rhs);
}

vec3 vec3::operator/=(const float& rhs) {
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	return *this;
}

vec3 vec3::operator/(const vec3& rhs) {
	return vec3(this->x/rhs.x, this->y/rhs.y, this->z/rhs.z);
}

vec3 vec3::operator/=(const vec3& rhs) {
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return *this;
}

bool vec3::operator==(const vec3& rhs) {
	return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

vec3 vec3::rotate(std::vector<float> matrix) {
	// Using a 4x4 opengl style matrix
	vec3 result = vec3(
		matrix[0]*x + matrix[1]*y + matrix[2]*z,
		matrix[4]*x + matrix[5]*y + matrix[6]*z,
		matrix[8]*x + matrix[9]*y + matrix[10]*z
	);
	return result;
}

vec3 vec3Lerp(const vec3& start, const vec3& end, const float& t) {
	return vec3(lerp(start.x, end.x, t), lerp(start.y, end.y, t), lerp(start.z, end.z, t));
}

vec3 cross(const vec3& a, const vec3& b) {
	return vec3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

float dot(vec3& a, vec3& b) {
	vec3 result = a * b;
	return result.x + result.y + result.z;
}

std::vector<float> rotationMatrix(float angle, vec3 vec) {
	vec3 v = vec.normalize();
	float cosT = cos(angle);
	float sinT = sin(angle);
	std::vector<float> result = {
		cosT + (1-cosT)*v.x*v.x, v.x*v.y*(1-cosT) - v.z*sinT, v.x*v.z*(1-cosT) + v.y*sinT, 0,
		v.x*v.y*(1-cosT) + v.z*sinT, cosT + (1-cosT)*v.y*v.y, v.y*v.z*(1-cosT) - v.x*sinT, 0,
		v.x*v.z*(1-cosT) - v.y*sinT, v.y*v.z*(1-cosT) + v.x*sinT, cosT + (1-cosT)*v.z*v.z, 0,
		0, 0, 0, 1
	};
	return result;
}

void debugLog(const vec3& vector, const char* message) {
	std::cout << message << vector.x << ", " << vector.y << ", " << vector.z << std::endl;
}
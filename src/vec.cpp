#include "../include/vec.h"

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

void debugLog(const vec3& vector, const char* message) {
	std::cout << message << vector.x << ", " << vector.y << ", " << vector.z << std::endl;
}
#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include "../include/mathlib.h"
#include <vector>

class vec3 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	vec3();
	vec3(GLfloat x, GLfloat y, GLfloat z);

	vec3 operator+(const vec3& rhs);
	vec3 operator-(const vec3& rhs);
	vec3 operator-();
	vec3 operator*(const vec3& rhs);
	vec3 operator*(const float& rhs);
	vec3 operator+=(const vec3& rhs);
	vec3 operator/(const float& rhs);
	vec3 operator/=(const float& rhs);
	vec3 operator/(const vec3& rhs);
	vec3 operator/=(const vec3& rhs);
	bool operator==(const vec3& rhs);

	float magnitude();
	float magnitude2();
	vec3 normalize();
	float sqrDist(const vec3& rhs);
	float angle(vec3& rhs);
	vec3 rotate(std::vector<float> matrix);
};

vec3 vec3Lerp(const vec3& start, const vec3& end, const float& t);
vec3 cross(const vec3& a, const vec3& b);
float dot(vec3& a, vec3& b);
std::vector<float> rotationMatrix(float angle, vec3 vec);

void debugLog(const vec3& vector, const char* message = "");
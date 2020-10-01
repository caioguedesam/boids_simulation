#pragma once

#include "../include/vec2.h"
#include "../include/vec3.h"
#include "../include/vec4.h"


/*#include <GL/freeglut.h>
#include <iostream>
#include "../include/mathlib.h"

class vec2 {
public:
	GLfloat x;
	GLfloat y;
	vec2();
	vec2(GLfloat x, GLfloat y);

	vec2 operator+(const vec2& rhs);
	vec2 operator-(const vec2& rhs);
	vec2 operator-();
	vec2 operator*(const vec2& rhs);
	vec2 operator*(const float& rhs);
	vec2 operator+=(const vec2& rhs);
	vec2 operator/(const float& rhs);
	vec2 operator/=(const float& rhs);
	vec2 operator/(const vec2& rhs);
	vec2 operator/=(const vec2& rhs);

	float magnitude();
	vec2 normalize();
	float sqrDist(const vec2& rhs);

	vec2 rotate(float angle);
};

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
	//quat operator*(const quat& rhs);
	vec3 operator+=(const vec3& rhs);
	vec3 operator/(const float& rhs);
	vec3 operator/=(const float& rhs);
	vec3 operator/(const vec3& rhs);
	vec3 operator/=(const vec3& rhs);

	float magnitude();
	vec3 normalize();
	float sqrDist(const vec3& rhs);
	float angle(vec3& rhs);
};

class vec4 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
	vec4();
	vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

	vec4 operator+(const vec4& rhs);
	vec4 operator-(const vec4& rhs);
	vec4 operator-();
	vec4 operator*(const vec4& rhs);
	vec4 operator*(const float& rhs);
	vec4 operator+=(const vec4& rhs);
	vec4 operator/(const float& rhs);
	vec4 operator/=(const float& rhs);
	vec4 operator/(const vec4& rhs);
	vec4 operator/=(const vec4& rhs);

	float magnitude();
	vec4 normalize();
	float sqrDist(const vec4& rhs);
};

vec3 vec3Lerp(const vec3& start, const vec3& end, const float& t);
vec3 cross(const vec3& a, const vec3& b);
float dot(vec3& a, vec3& b);

void debugLog(const vec3& vector, const char* message = "");*/
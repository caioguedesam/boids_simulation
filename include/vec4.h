#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include "../include/mathlib.h"

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
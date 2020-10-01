#pragma once
#include <GL/freeglut.h>
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
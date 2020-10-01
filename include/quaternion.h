#pragma once
#include "../include/vec.h"
#include <vector>

class quat : public vec4 {
public:
    quat();
    quat(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

    quat operator*(const quat& rhs);

    quat conjugate();
    quat normalize();
    std::vector<float> toMatrix();
    std::vector<float> rotationMatrix();

    void print();

    static quat identity();
    static quat angleAxis(float angle, vec3 axis);
};
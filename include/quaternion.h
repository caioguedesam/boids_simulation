#pragma once
#include "../include/vec4.h"

class quat : public vec4 {
public:
    quat();
    quat(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

    quat operator*(const quat& rhs);

    quat conjugate();
    void identity();
};
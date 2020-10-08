#pragma once
#include "../include/vec.h"
#include "../include/boid.h"
#include <vector>

class Ground {
public:
    vec3 position;
    vec2 size;

    Ground();
    Ground(vec3 position, vec2 size);

    void setMaterial();
    void draw();
    bool isNearBoid(Boid* boid, const float& radius);
};
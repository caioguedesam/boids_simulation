#pragma once
#include "../include/obj_loader.h"
#include "../include/vec.h"
#include "../include/model.h"
#include <vector>

class Tower {
public:
    vec3 position;
    vec3 scale;

    Tower();
    Tower(vec3 position, vec3 scale = vec3(1,1,1));

    void setMaterial();
    void draw();
};
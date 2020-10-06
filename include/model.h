#pragma once
#include <vector>
#include "../include/obj_loader.h"

class Model {
public:
    std::vector<float> vertices, uvs, normals;
    Model();
    Model(std::vector<float> vertices, std::vector<float> uvs, std::vector<float> normals);
};
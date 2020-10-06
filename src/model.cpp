#include "../include/model.h"

Model::Model() {}

Model::Model(std::vector<float> vertices, std::vector<float> uvs, std::vector<float> normals) {
    this->vertices = vertices;
    this->uvs = uvs;
    this->normals = normals;
}
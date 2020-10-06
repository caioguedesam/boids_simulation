#pragma once
#include "../include/vec.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

bool loadOBJ(const char* path, 
    std::vector<float>& outVertices,
    std::vector<float>& outUVs,
    std::vector<float>& outNormals);

std::vector<std::string> splitString(std::string str, char delim = ' ');
std::vector<std::string> splitStringOnce(std::string str, char delim = ' ');
std::vector<float> convertToFloatValues(const std::vector<std::string>& vec);
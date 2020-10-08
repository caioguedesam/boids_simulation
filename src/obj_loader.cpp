#include "../include/obj_loader.h"

bool loadOBJ(const char* path, 
    std::vector<float>& outVertices,
    std::vector<float>& outUVs,
    std::vector<float>& outNormals) {

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<vec3> tempVertices, tempNormals;
    std::vector<vec2> tempUVs;

    std::string line;
    std::ifstream file(path);
    if(file.is_open()) {
        // Parse each line from file
        while(std::getline(file, line)) {
            std::vector<std::string> contents = splitStringOnce(line, ' ');
            std::string firstWord = contents[0];
            std::string data = contents[1];

            if(firstWord == "#") continue;
            // Parse vertex
            else if(firstWord == "v") {
                std::vector<float> vertexValues = convertToFloatValues(splitString(data));
                vec3 vertex = vec3(vertexValues[0], vertexValues[1], vertexValues[2]);
                tempVertices.push_back(vertex);
            }
            // Parse UV coordinates
            else if(firstWord == "vt") {
                std::vector<float> UVs = convertToFloatValues(splitString(data));
                vec2 texcoord = vec2(UVs[0], UVs[1]);
                tempUVs.push_back(texcoord);
            }
            // Parse normal
            else if(firstWord == "vn") {
                std::vector<float> normalValues = convertToFloatValues(splitString(data));
                vec3 normal = vec3(normalValues[0], normalValues[1], normalValues[2]);
                tempNormals.push_back(normal);
            }
            // Parse face
            else if(firstWord == "f") {
                std::vector<std::string> faceContents = splitString(data);
                if(faceContents.size() > 3) {
                    std::cout << "Error: face not triangle, can't be handled by parser." << std::endl;
                    return false;
                }

                for(auto it = faceContents.begin(); it != faceContents.end(); it++) {
                    std::vector<float> values = convertToFloatValues(splitString(*it, '/'));
                    vertexIndices.push_back(values[0]);
                    uvIndices.push_back(values[1]);
                    normalIndices.push_back(values[2]);
                }
            }
        }

        // Get data from indexes into out arrays
        for(int i = 0; i < vertexIndices.size(); i++) {
            int vertexIndex = vertexIndices[i];
            int uvIndex = uvIndices[i];
            int normalIndex = normalIndices[i];

            // -1 because .obj indexation starts from 1 instead of 0
            vec3 vertex = tempVertices[vertexIndex - 1];
            vec2 uv = tempUVs[uvIndex - 1];
            vec3 normal = tempNormals[normalIndex - 1].normalize();

            outVertices.push_back(vertex.x);
            outVertices.push_back(vertex.y);
            outVertices.push_back(vertex.z);
            outUVs.push_back(uv.x);
            outUVs.push_back(uv.y);
            outNormals.push_back(normal.x);
            outNormals.push_back(normal.y);
            outNormals.push_back(normal.z);
        }

        file.close();
        return true;
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }
}

std::vector<std::string> splitString(std::string str, char delim) {
    std::istringstream iss(str);
    std::vector<std::string> result;
    std::string temp;
    while(std::getline(iss, temp, delim)) {
        result.push_back(temp);
    }
    return result;
}

std::vector<std::string> splitStringOnce(std::string str, char delim) {
    std::size_t delimPos = str.find(delim);
    std::vector<std::string> result;
    result.push_back(str.substr(0, delimPos));
    result.push_back(str.substr(delimPos + 1));
    return result;
}

std::vector<float> convertToFloatValues(const std::vector<std::string>& vec) {
    std::vector<float> result;
    for(auto it = vec.begin(); it != vec.end(); it++) {
        result.push_back(std::stof(*it));
    }
    return result;
}
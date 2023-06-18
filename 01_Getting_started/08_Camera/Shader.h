#ifndef SHADERS_SHADER_H
#define SHADERS_SHADER_H

#include <glad/glad.h>

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

class Shader
{
public:
    // Program ID
    unsigned int progId;

    // Shader constructor
    Shader(const char *vertexPath, const char *fragmentPath);

    // Active or use the program
    void use();

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;
};


#endif //SHADERS_SHADER_H

#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::string vertexSrc;
    std::string fragmentSrc;
    std::ifstream vsFile;
    std::ifstream fsFile;

    vsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vsFile.open(vertexPath);
        fsFile.open(fragmentPath);

        std::stringstream vsStream;
        std::stringstream fsStream;

        vsStream << vsFile.rdbuf();
        fsStream << fsFile.rdbuf();

        vsFile.close();
        fsFile.close();

        vertexSrc = vsStream.str();
        fragmentSrc = fsStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "[ERROR] SHADER::SHADER_FILE_READ_FAILED." << std::endl;
    }

    unsigned int vertex;
    unsigned int fragment;
    int success;
    char infoLog[512];
    const char *vertexCode = vertexSrc.c_str();
    const char *fragmentCode = fragmentSrc.c_str();

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, nullptr);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "[ERROR] SHADER::VERTEX::COMPILATION_FAILED.\t" << infoLog << std::endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, nullptr);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "[ERROR] SHADER::FRAGMENT::COMPILATION_FAILED.\t" << infoLog << std::endl;
    }

    progId = glCreateProgram();
    glAttachShader(progId, vertex);
    glAttachShader(progId, fragment);
    glLinkProgram(progId);
    glGetProgramiv(progId, GL_LINK_STATUS, &success);
    if (!success){
        glGetProgramInfoLog(progId, 512, nullptr, infoLog);
        std::cout << "[ERROR] SHADER::PROGRAM::LINK_FAILED.\t" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(progId);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(progId, name.c_str()), (int) value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(progId, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(progId, name.c_str()), value);
}

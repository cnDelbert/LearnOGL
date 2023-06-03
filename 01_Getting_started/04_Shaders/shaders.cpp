#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();
//    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Learning OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    int mAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &mAttributes);
    std::cout << "OpenGL version is " << glGetString(GL_VERSION) << "\nGL vender is " << glGetString(GL_VENDOR)
              << std::endl;
    std::cout << "Max number of vertex attributes support is " << mAttributes << std::endl;
    return 0;
}

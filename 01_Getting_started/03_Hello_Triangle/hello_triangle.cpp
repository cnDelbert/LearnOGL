#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int WIN_HEIGHT = 600;
constexpr int WIN_WIDTH = 800;

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, 100, 100);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // For MacOS system os only
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Learning OpenGL", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        // Outside keyboard input process
        processInput(window);

        // Rendering
        glClearColor(02.f, 0.3f, 0.4f, 0.5f);   // 状态设置函数
        glClear(GL_COLOR_BUFFER_BIT);   // 状态使用函数

        // Swap Buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#include "Shader.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <cmath>

constexpr int WIN_HEIGHT = 600;
constexpr int WIN_WIDTH = 800;

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, 100, 100);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void changeUniformValue(GLuint program)
{
    float timeValue = (float) glfwGetTime();
    float greenValue = (std::sin(timeValue) / 2.0f) + 0.5f;
    int colorLocation = glGetUniformLocation(program, "ourColor");
    glUseProgram(program);
    glUniform3f(colorLocation, 0.0f, greenValue, 0.0f);
}

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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return -1;
    }

    float vertices[] = {
            // 位置              // 颜色
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // 右下
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // 左下
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // 顶部
    };

    float texCoords[] = {
            0.0f, 0.0f, // 左下角
            1.0f, 0.0f, // 右下角
            0.5f, 1.0f // 上中
    };

    int success;
    char infoLog[512];

    Shader glShader("vertex.shader", "fragment.shader");
//    glShader.use();

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    int width;
    int height;
    int nrChannels;
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        // Outside keyboard input process
        processInput(window);

        // Rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);   // 状态设置函数
        glClear(GL_COLOR_BUFFER_BIT);   // 状态使用函数

        glShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0);

        // Swap Buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

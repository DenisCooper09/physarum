#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define ERROR(format, ...) fprintf(stderr, "[ERROR] %s:%i\t| " format "\n", __FILE__, __LINE__, ##__VA_ARGS__)

static void glfw_error_callback(int error_code, const char *description)
{
    ERROR("GLFW ERROR: 0x%08X - %s", error_code, description);
}

static void glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit())
    {
        ERROR("GLFW failed to initialize.");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1720, 880, "OpenGL", 0, 0);
    if (!window)
    {
        ERROR("GLFW failed to create window.");
        glfwTerminate();
        return -2;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        ERROR("GLAD failed to load OpenGL loader.");
        glfwTerminate();
        return -3;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

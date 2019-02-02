#include "loop.h"

// main loop
void loop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window))
    {
        logic();
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void logic() {

}

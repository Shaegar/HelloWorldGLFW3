#include "input.h"

#include <GLFW/glfw3.h>

double xpos = 0;
double ypos = 0;
bool pan = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  if (button == 0) {
    if (action == GLFW_PRESS) {
      pan = true;
    } else {
      pan = false;
    }
  }
}

void cursor_pos_callback(GLFWwindow* window, double x, double y) {
  if (pan) {

  }
  xpos = x;
  ypos = y;
}
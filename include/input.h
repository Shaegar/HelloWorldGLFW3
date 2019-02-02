#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

  #include <GLFW/glfw3.h>

  //callbacks
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
  void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
  void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

#endif // INPUT_H_INCLUDED

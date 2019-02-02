#include "loop.h"

// main loop
void loop(GLFWwindow* window, std::initializer_list<Drawable*> list) {
  while (!glfwWindowShouldClose(window))
  {
    logic(list);
    render(list);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void render(std::initializer_list<Drawable*> list) {
  for (Drawable* elem : list) {
    elem->draw();
  }
}

void logic(std::initializer_list<Drawable*> list) {
  for (Drawable* elem : list) {
    elem->update();
  }
}

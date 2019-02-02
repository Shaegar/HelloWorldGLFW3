#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

  #include "drawable.h"
  #include <initializer_list>

  void loop(GLFWwindow* window, std::initializer_list<Drawable*> list);
  void render(std::initializer_list<Drawable*> list);
  void logic(std::initializer_list<Drawable*> list);

#endif

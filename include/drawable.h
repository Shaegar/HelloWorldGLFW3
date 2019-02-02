#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Drawable {
  public:
    virtual void draw() = 0;
    virtual void update() = 0;
};

#endif // DRAWABLE_H_INCLUDED

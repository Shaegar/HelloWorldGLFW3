#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "loop.h"
#include "input.h"

#include "drawable.h"
#include "pc.h"
#include "level.h"
#include "camera.h"
#include "grid.h"

#include <cstdio>
#include <stdexcept>

using namespace std;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void reshape( GLFWwindow* window, int width, int height )
{
  GLfloat h = (GLfloat) height / (GLfloat) width;
  GLfloat xmax, znear, zfar;

  znear = 5.0f;
  zfar  = 30.0f;
  xmax  = znear * 0.5f;

  glViewport( 0, 0, (GLint) width, (GLint) height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glFrustum( -xmax, xmax, -xmax*h, xmax*h, znear, zfar );
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( 0.0, 0.0, -20.0 );
}

GLFWwindow* setupGlfw() {
  GLFWwindow* window;
  if (glfwInit()) {
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    window = glfwCreateWindow(1280, 720, "oh hai thar", NULL, NULL);
    if (window) {
      glfwMakeContextCurrent(window);
      glfwSetErrorCallback(error_callback);
      glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
      if(glewInit() == GLEW_OK) {
        if(!GLEW_VERSION_3_2) {
          throw std::runtime_error("OpenGL 3.2 API is not available.");
        }
      } else {
        throw std::runtime_error("glewInit failed");
      }
    } else {
      throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    }
  } else {
    throw std::runtime_error("glfwInit failed");
  }
  return window;
}

int main(void) {
    GLFWwindow* window = setupGlfw();
    if (window) {
      glfwSetKeyCallback(window, key_callback);
      glfwSetMouseButtonCallback(window, mouse_button_callback);
      glfwSetCursorPosCallback(window, cursor_pos_callback);
      glfwSetFramebufferSizeCallback(window, reshape);
      PC* pc = new PC();
      Level* level = new Level(1);
      Grid* grid = new Grid();
      loop(window, {pc, level, grid});
      glfwTerminate();
      return 0;
    } else {
      return -1;
    }
}
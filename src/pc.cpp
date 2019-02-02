#include "pc.h"

int PC::getHealth(void) {
	return health;
}

float PC::getX(void) {
	return x;
}

float PC::getY(void) {
	return y;
}

void PC::startMoving(void) {
	moving = true;
}

void PC::stopMoving(void) {
	moving = false;
}

void PC::update() {

}

void PC::draw() {

//  float vertices[] = {
//     0.0f,  0.5f, // Vertex 1 (X, Y)
//     0.5f, -0.5f, // Vertex 2 (X, Y)
//    -0.5f, -0.5f  // Vertex 3 (X, Y)
//  };
//
//  GLuint vbo;
//  glGenBuffers(1, &vbo); // Generate 1 buffer
//
//  glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f,  0.5f);
  glVertex2f(0.5f, -0.5f);
  glVertex2f(-0.5f, -0.5f);
	glEnd();
}

#include "level.h"

Level::Level(const float height) {
  setHeight(height);
};

float Level::getHeight() {
  return height;
};

void Level::setHeight(const float value) {
  this->height = value;
};

void Level::draw() {
//  glBegin(GL_POLYGON);
//  glVertex2d(0, 0);
//  glVertex2d(1, 0);
//  glVertex2d(1, height);
//  glVertex2d(0, height);
//  glEnd();
};

void Level::update() {
  //todo
};

#define _USE_MATH_DEFINES
#include <cmath>
#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

static const float MaxPitch = 85.0f; //must be less than 90 to avoid gimbal lock

Camera::Camera() :
  pos(0.0f, 0.0f, 1.0f),
  yaw(0.0f),
  pitch(0.0f),
  fov(50.0f),
  nearPlane(0.01f),
  farPlane(100.0f),
  viewportAspectRatio(4.0f/3.0f)
{
}

const glm::vec3& Camera::getPos() const {
  return pos;
}

void Camera::setPos(const glm::vec3& pos) {
  this->pos = pos;
}

void Camera::offsetPos(const glm::vec3& offset) {
  pos += offset;
}

float Camera::getFov() const {
  return fov;
}

void Camera::setFov(float fov) {
  assert(fov > 0.0f && fov < 180.0f);
  this->fov = fov;
}

float Camera::getNearPlane() const {
  return nearPlane;
}

float Camera::getFarPlane() const {
  return farPlane;
}

void Camera::setNearAndFarPlanes(float nearPlane, float farPlane) {
  assert(nearPlane > 0.0f);
  assert(farPlane > nearPlane);
  this->nearPlane = nearPlane;
  this->farPlane = farPlane;
}

glm::mat4 Camera::orientation() const {
  glm::mat4 orientation;
  orientation = glm::rotate(orientation, glm::radians(pitch), glm::vec3(1,0,0));
  orientation = glm::rotate(orientation, glm::radians(yaw), glm::vec3(0,1,0));
  return orientation;
}

void Camera::offsetOrientation(float upAngle, float rightAngle) {
  yaw += rightAngle;
  pitch += upAngle;
  normalizeAngles();
}

void Camera::lookAt(glm::vec3 pos) {
  //assert(pos != this->pos);
  glm::vec3 direction = glm::normalize(pos - this->pos);
  pitch = glm::radians(asinf(-direction.y));
  yaw = -glm::radians(atan2f(-direction.x, -direction.z));
  normalizeAngles();
}

float Camera::getViewportAspectRatio() const {
  return viewportAspectRatio;
}

void Camera::setViewportAspectRatio(float viewportAspectRatio) {
  assert(viewportAspectRatio > 0.0);
  this->viewportAspectRatio = viewportAspectRatio;
}

glm::vec3 Camera::forward() const {
  glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0,0,-1,1);
  return glm::vec3(forward);
}

glm::vec3 Camera::right() const {
  glm::vec4 right = glm::inverse(orientation()) * glm::vec4(1,0,0,1);
  return glm::vec3(right);
}

glm::vec3 Camera::up() const {
  glm::vec4 up = glm::inverse(orientation()) * glm::vec4(0,1,0,1);
  return glm::vec3(up);
}

glm::mat4 Camera::matrix() const {
  return projection() * view();
}

glm::mat4 Camera::projection() const {
  return glm::perspective(glm::radians(fov), viewportAspectRatio, nearPlane, farPlane);
}

glm::mat4 Camera::view() const {
  return orientation() * glm::translate(glm::mat4(), -pos);
}

void Camera::normalizeAngles() {
  yaw = fmodf(yaw, 360.0f);
  if (yaw < 0.0f) {
    yaw += 360.0f;
  }
  if (pitch > MaxPitch) {
    pitch = MaxPitch;
  } else if(pitch < -MaxPitch) {
    pitch = -MaxPitch;
  }
}
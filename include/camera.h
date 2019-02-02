#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <glm/glm.hpp>

class Camera {
private:
  glm::vec3 pos;
  float yaw;
  float pitch;
  float fov;
  float nearPlane;
  float farPlane;
  float viewportAspectRatio;
  void normalizeAngles();
public:
  Camera();
  const glm::vec3& getPos() const;
  void setPos(const glm::vec3& pos);
  void offsetPos(const glm::vec3& offset);
  float getFov() const;
  void setFov(float fov);
  float getNearPlane() const;
  float getFarPlane() const;
  void setNearAndFarPlanes(float nearPlane, float farPlane);
  glm::mat4 orientation() const;
  void offsetOrientation(float upAngle, float rightAngle);
  void lookAt(glm::vec3 position);
  float getViewportAspectRatio() const;
  void setViewportAspectRatio(float viewportAspectRatio);
  glm::vec3 forward() const;
  glm::vec3 right() const;
  glm::vec3 up() const;
  glm::mat4 matrix() const;
  glm::mat4 projection() const;
  glm::mat4 view() const;
};

#endif // CAMERA_H_INCLUDED

#include "camera.hpp"
#include <iostream>
#include <string>

Camera::Camera()
{

}

Camera::Camera(std::string name,double horizontal_apex_angle, glm::ivec2 resolution):name_(name),horizontal_apex_angle(horizontal_apex_angle)
{
  resolution.x = resolution.x;
 resolution.y = resolution.y;

}

void Camera::setname(std::string name)
{
    name_ = name;
}

void Camera::setangle(double angle)
{
    horizontal_apex_angle = angle;
}

void Camera::setResolution_x(double resx)
{
    resolution.x = resx;
}

void Camera::setResolution_y(double resy)
{
    resolution.y = resy;
}

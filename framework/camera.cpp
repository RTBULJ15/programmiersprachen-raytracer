#include "camera.hpp"
#include <iostream>
#include <string>

Camera::Camera()
: name_{"default"}, horizontal_apex_angle_{}
{}

Camera::Camera(std::string name,double horizontal_apex_angle/*,glm::ivec2 resolution*/)
:name_(name),horizontal_apex_angle_(horizontal_apex_angle)
{}

void Camera::setname(std::string name)
{
    name_ = name;
}

void Camera::setangle(double angle)
{
    horizontal_apex_angle_ = angle;
}

/*void Camera::setResolution_x(double resx)
{
    resolution.x = resx;
}

void Camera::setResolution_y(double resy)
{
    resolution.y = resy;
}*/

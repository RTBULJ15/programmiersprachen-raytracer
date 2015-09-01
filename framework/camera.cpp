#include "camera.hpp"
#include <iostream>
#include <string>
#include <math.h>

Camera::Camera()
: name_{"default"}, focal_length_{1}
{}

Camera::Camera(std::string const& name, double horizontal_apex_angle)
: name_(name)
, focal_length_(1 / glm::tan(horizontal_apex_angle * M_PI / 360))
{}

std::string 
Camera::name () const 
{
	return name_;
}

void Camera::setname(std::string const& name)
{
    name_ = name;
}

void Camera::setangle(double angle)
{
    focal_length_ = 1 / glm::tan(angle * M_PI / 360);
}

double 
Camera::focallength () const {
	return focal_length_;
}

/*void Camera::setResolution_x(double resx)
{
    resolution.x = resx;
}

void Camera::setResolution_y(double resy)
{
    resolution.y = resy;
}*/

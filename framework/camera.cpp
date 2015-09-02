#include "camera.hpp"
#include <iostream>
#include <string>
#include <math.h>

Camera::Camera()
: name_{"default"}, focal_length_{1}, world_transform_(), world_transform_inv_()
{}

Camera::Camera(Camera const& rhs)
: name_{rhs.name_}, focal_length_{rhs.focal_length_}
, world_transform_(rhs.world_transform_), world_transform_inv_(rhs.world_transform_inv_)
{}

Camera::Camera(std::string const& name, double horizontal_apex_angle,
	glm::dvec3 const& eye, glm::dvec3 const& dir, glm::dvec3 const& up)
: name_(name)
, focal_length_(1 / glm::tan(horizontal_apex_angle * M_PI / 360))
, world_transform_(), world_transform_inv_()
{
  auto u = glm::normalize(glm::cross(dir, up));
  auto v = glm::normalize(glm::cross(u, dir));
  auto n = glm::normalize(dir);

  world_transform_[0] = glm::dvec4(u, 0.0f);
  world_transform_[1] = glm::dvec4(v, 0.0f);
  world_transform_[2] = glm::dvec4(n, 0.0f);
  world_transform_[3] = glm::dvec4(eye, 1.0f);
  world_transform_inv_ = glm::inverse(world_transform_);
}

std::shared_ptr<Camera>
Camera::clone () const 
{
  return std::make_shared<Camera>(*this);
}

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

Ray 
Camera::generateRay(glm::dvec2 const& viewPlaneCoord, int const rayD) const{
	glm::dvec3 origin(0.0f, 0.0f, 0.0f);
	auto direction = glm::normalize(glm::dvec3(
    2*viewPlaneCoord.x-1, 2*viewPlaneCoord.y-1, focal_length_));
	Ray r = world_transform_* Ray(origin, direction, rayD);
	r.direction = glm::normalize(r.direction);
	return r;
}

void
Camera::translate(glm::dvec3 const& t)
{
  auto m = glm::translate(glm::dmat4(), t);
  world_transform_ = m * world_transform_;
  world_transform_inv_ = world_transform_inv_ * m;
}

void
Camera::rotate(double rad, glm::dvec3 const& axis)
{
  auto m = glm::rotate(glm::dmat4(), rad, axis);
  world_transform_ = m * world_transform_;
  world_transform_inv_ = world_transform_inv_ * m;
}

/*void Camera::setResolution_x(double resx)
{
    resolution.x = resx;
}

void Camera::setResolution_y(double resy)
{
    resolution.y = resy;
}*/

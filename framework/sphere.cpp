#define _USE_MATH_DEFINES
#include <cmath>

#include "Sphere.hpp"

Sphere::Sphere(): center_(0.0f,0.0f,0.0f), radius_(0.0f)
{}

Sphere::Sphere(glm::vec3 const& center, float radius): center_(center), radius_(radius)
{}

glm::vec3 Sphere::getcenter() const{
  return center_;
}

float Sphere::getradius() const{
  return radius_;
}

float Sphere::area() const{
  return 4.0*M_PI*(radius_*radius_);
}

float Sphere::volume() const{
  return (3.0/4.0)*M_PI*(radius_*radius_*radius_);
}

Sphere::~Sphere()
{}
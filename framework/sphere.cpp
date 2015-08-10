#define _USE_MATH_DEFINES
#include <cmath>

#include "Sphere.hpp"
#include "color.hpp"
#include <glm/gtx/intersect.hpp>

Sphere::Sphere()
  : Shape{}, center_{0.0f,0.0f,0.0f}, radius_{0.0f}
{}


Sphere::Sphere(glm::vec3 const& center, float radius, std::string name, Material const& material)
  : Shape(name, material), center_(center), radius_(radius) //Shape::setName(name), Shape::setColor(color)
{}

glm::vec3 Sphere::getcenter() const{
  return center_;
}

float Sphere::getradius() const{
  return radius_;
}

/*float Sphere::area() const{
  return 4.0*M_PI*(radius_*radius_);
}

float Sphere::volume() const{
  return (4.0/3.0)*M_PI*(radius_*radius_*radius_);
} */

void Sphere::print(std::ostream& os) const{
	Shape::print(os);
	os << "Radius: " << radius_ << " Center: " << center_.x << center_.y << center_.z<<std::endl;
}

Intersection Sphere::intersect(Ray const& ray) const {

	Intersection intersect;
	intersect.hit = glm::intersectRaySphere(
		ray.origin, ray.direction, 				// ray parameters
		center_, radius_, 						// sphere parameters
		intersect.position, intersect.normal 	// return per reference
	);

	return intersect;
}

Sphere::~Sphere()
{
	std::cout << "~Sphere destructor called" << std::endl;
}

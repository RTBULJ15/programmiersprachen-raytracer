#define _USE_MATH_DEFINES
#include <cmath>

#include "Sphere.hpp"
#include "color.hpp"
#include <glm/gtx/intersect.hpp>

Sphere::Sphere()
  : Shape{}, center_{0.0f,0.0f,0.0f}, radius_{0.0f}
{}


Sphere::Sphere(glm::vec3 const& center, float radius, std::string name, std::shared_ptr<Material> const& material)
  : Shape(name, material), center_(center), radius_(radius) //Shape::setName(name), Shape::setColor(color)
{}

glm::vec3 Sphere::getcenter() const{
  return center_;
}

void Sphere::setcenter_x(double centerx)&
{
    center_.x = centerx;
}

void Sphere::setcenter_y(double centery)&
{
    center_.y = centery;
}

void Sphere::setcenter_z(double centerz)&
{
    center_.z = centerz;
}

float Sphere::getradius() const{
  return radius_;
}

void Sphere::setradius(double radius)&
{
    radius_ = radius;
}

 glm::vec3 Sphere::kreisNormale(glm::vec3 const& mittelpunkt, glm::vec3 const& surface) const{
    glm::vec3 ausgabe;
      ausgabe[0]=surface[0]-mittelpunkt[0];
      ausgabe[1]=surface[1]-mittelpunkt[1];
      ausgabe[2]=surface[2]-mittelpunkt[2];
    return ausgabe;
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
	//Schnittpunkt berechnen
	glm::vec3 L= center_-ray.origin;
	
	glm::vec3 tc= L*(float(cos((glm::dot(L, ray.direction)*3.14159/180)))); // degree into radiant
	//float L_length = glm::distance(glm::vec3{0,0,0},L);
	glm::vec3 d_temp = (L*L) - (tc*tc);
	glm::vec3 d(sqrtf(d_temp[0]),sqrtf(d_temp[1]),sqrtf(d_temp[2]));

	glm::vec3 t1c_temp = (radius_ * radius_) - (d*d);
	glm::vec3 t1c(sqrtf(t1c_temp[0]),sqrtf(t1c_temp[1]),sqrtf(t1c_temp[2]));
	glm::vec3 t1 = tc - t1c;

	glm::vec3 P1 = (ray.origin + ray.direction) * t1; //<--Schnittpunkt
	glm::vec3 normale = Sphere::kreisNormale(center_, P1); //Spherenormale am Schnittpunkt 




	Intersection intersect;
	intersect.hit = glm::intersectRaySphere(
		ray.origin, ray.direction, 				// ray parameters
		center_, radius_, 						// sphere parameters
		intersect.position, intersect.normal 	// return per reference
	);
	// intersect.position = P1;
	// intersect.normal = normale;

	return intersect;
}

Sphere::~Sphere()
{
	std::cout << "~Sphere destructor called" << std::endl;
}

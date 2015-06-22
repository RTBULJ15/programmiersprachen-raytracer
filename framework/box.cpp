#include "Box.hpp"

Box::Box()
  : min_(0,0,0), max_(0,0,0)
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max)
  : min_(min), max_(max)
{}

glm::vec3 Box::getMin() const{
	return min_;
}
glm::vec3 Box::getMax() const{
	return max_;
}

float Box::area() const{
	
	glm::vec3 vecTemp=max_-min_;
	float side_a=vecTemp.x;
	float side_b=vecTemp.y;
	float side_c=vecTemp.z;
	
	return 2.0f*(side_a*side_b)+2.0f*(side_a*side_c)+2.0f*(side_b*side_c);
}

float Box::volume() const{

	glm::vec3 vecTemp=max_-min_;
	float side_a=vecTemp.x;
	float side_b=vecTemp.y;
	float side_c=vecTemp.z;
	
	return side_a*side_b*side_c;
}
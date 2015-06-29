#include "Box.hpp"
#include "color.hpp"
#include <glm/gtx/intersect.hpp>

Box::Box()
  : Shape{}, min_(0,0,0), max_(0,0,0)
{}


Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color)
  : Shape(name, color), min_(min), max_(max)
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


void Box::print(std::ostream& os) const{
	Shape::print(os);
	os << "MinVec: " << min_.x << min_.y << min_.z;
	os << " MaxVec: " << max_.x << max_.y << max_.z;
}

/*bool Box::intersect(Ray & ray) const&{

		Trianglebox tri11{{min_.x, min_.y, min_.z},{min_.x, max_.y, min_.z},{max_.x, max_.y, min_.z}}; //boxfront
		Trianglebox tri12{{min_.x, min_.y, min_.z},{max_.x, min_.y, min_.z},{max_.x, max_.y, min_.z}}; //boxfront

		Trianglebox tri21{{min_.x, min_.y, min_.z},{min_.x, min_.y, max_.z},{max_.x, min_.y, max_.z}}; //underside
		Trianglebox tri22{{min_.x, min_.y, min_.z},{max_.x, min_.y, min_.z},{max_.x, min_.y, max_.z}}; //underside

		Trianglebox tri31{{min_.x, max_.y, min_.z},{min_.x, max_.y, max_.z},{max_.x, max_.y, max_.z}}; //overside
		Trianglebox tri32{{min_.x, max_.y, min_.z},{max_.x, max_.y, min_.z},{max_.x, max_.y, max_.z}}; //overside

		Trianglebox tri41{{min_.x, min_.y, min_.z},{min_.x, max_.y, min_.z},{min_.x, max_.y, max_.z}}; //leftside
		Trianglebox tri42{{min_.x, min_.y, min_.z},{min_.x, max_.y, max_.z},{min_.x, max_.y, max_.z}}; //leftside

		Trianglebox tri51{{max_.x, min_.y, min_.z},{max_.x, max_.y, min_.z},{max_.x, max_.y, max_.z}}; //rigthside
		Trianglebox tri52{{max_.x, min_.y, min_.z},{max_.x, min_.y, max_.z},{max_.x, max_.y, max_.z}}; //rigthside

		bool intersect=false;
		glm::vec3 hitposition;

		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri11.v1, tri11.v2, tri11.v3, hitposition){intersect=true;};
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri12.v1, tri12.v2, tri12.v3, hitposition){intersect=true;};
		
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri21.v1, tri21.v2, tri21.v3, hitposition){intersect=true;};
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri22.v1, tri22.v2, tri22.v3, hitposition){intersect=true;};
		
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri31.v1, tri31.v2, tri31.v3, hitposition){intersect=true;};
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri32.v1, tri32.v2, tri32.v3, hitposition){intersect=true;};
		
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri41.v1, tri41.v2, tri41.v3, hitposition){intersect=true;};
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri42.v1, tri42.v2, tri42.v3, hitposition){intersect=true;};
		
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri51.v1, tri51.v2, tri51.v3, hitposition){intersect=true;};
		if (glm::intersectRayTriangle(ray.origin, ray.direction, tri52.v1, tri52.v2, tri52.v3, hitposition){intersect=true;};
 return intersect;
}*/
	/*Intersection intersect;
	intersect.hit = glm::intersectRayPlane(
		ray.origin, ray.direction, 				// ray parameters
		center_, radius_, 						// sphere parameters
		intersect.position, intersect.normal 	// return per reference
	);*/
/*
bool glm::gtx::intersect::intersectRayTriangle 	( 	
		genType const &  	orig,
		genType const &  	dir,
		genType const &  	vert0,
		genType const &  	vert1,
		genType const &  	vert2,
		genType &  	baryPosition 
	) 	


*/
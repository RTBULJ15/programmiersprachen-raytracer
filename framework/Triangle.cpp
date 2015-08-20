#include "Triangle.hpp"

Triangle::Triangle() : Shape(), v1_(), v2_(), v3_(), n_() {}

Triangle::Triangle(glm::vec3 const& u, glm::vec3 const& v, glm::vec3 const& w)
: Shape()
, v1_(u)
, v2_(v)
, v3_(w)
, n_(glm::normalize(glm::cross(v3_ - v1_, v2_ - v1_))) 
{}

glm::vec3 
Triangle::v1 () const {
	return v1_;
}

glm::vec3 
Triangle::v2 () const {
	return v2_;
}

glm::vec3 
Triangle::v3 () const {
	return v3_;
}


Intersection 
Triangle::intersect (Ray const& ray) const 
{
	glm::vec3 bary;
	Intersection isec;

	isec.hit = glm::intersectRayTriangle (
		ray.origin, ray.direction, 
		v1_, v2_, v3_, 
		bary
		);

	if (isec.hit) {
		isec.normal = n_;
		isec.position = barycentric_to_world(bary);
		isec.t = glm::length(isec.position - ray.origin);
	}

	return isec;
}

glm::vec3 
Triangle::barycentric_to_world (glm::vec3 const& bary) const 
{
	glm::vec3 result;
	double u, v, w;

	u = bary.x;
	v = bary.y;
	w = 1 - (u+v);

	result.x = (u * v1_.x + v * v2_.x + w * v3_.x);
	result.y = (u * v1_.y + v * v2_.y + w * v3_.y);
	result.z = (u * v1_.z + v * v2_.z + w * v3_.z);

	return result;
}

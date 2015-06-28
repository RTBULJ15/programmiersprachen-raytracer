#ifndef BUW_INTERSECTION_HPP
#define BUW_INTERSECTION_HPP

#include <glm/glm.hpp>
struct Intersection
{
	Intersection () : hit(false), position(), normal() {}

	Intersection (bool h, glm::vec3 const& p, glm::vec3 const& n)
	 : hit(h)
	 , position(p)
	 , normal(n)
	{}

	bool hit;

	glm::vec3 position;

	glm::vec3 normal;

};

#endif // BUW_INTERSECTION_HPP
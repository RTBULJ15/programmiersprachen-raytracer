#ifndef BUW_INTERSECTION_HPP
#define BUW_INTERSECTION_HPP

#include <glm/glm.hpp>
#include <iostream>
#include <string>

struct Intersection
{
	Intersection () : hit(false), t(-1), position(), normal() {}

	Intersection (bool h, double ray_t, glm::vec3 const& p, glm::vec3 const& n)
	 : hit(h && ray_t >= 0)
	 , position(p)
	 , normal(n)
	 , t(ray_t)
	{}

	bool hit;

	glm::vec3 position;

	double t;

	glm::vec3 normal;

};

// std::ostream& operator << (std::ostream& o, Intersection const& intersection)
// 	  {
// 	  // o << "Position" << intersection.position[0] << " " << intersection.position[1] << " " << intersection.position[2] << std::endl;
// 	  o << "Position" << intersection.position[0] << std::endl;

// 	  return o;
// 	  }


#endif // BUW_INTERSECTION_HPP
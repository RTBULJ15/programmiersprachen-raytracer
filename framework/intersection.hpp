#ifndef BUW_INTERSECTION_HPP
#define BUW_INTERSECTION_HPP

#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <memory>
#include "Material.hpp"

struct Intersection
{
	Intersection () : hit(false), t(-1), position(), normal(), material() {}

	Intersection (bool h, double ray_t, glm::dvec3 const& p, glm::dvec3 const& n, std::shared_ptr<Material> mat)
	 : hit(h && ray_t >= 0)
	 , position(p)
	 , normal(n)
	 , t(ray_t)
	 , material(mat)
	{}

	bool hit;

	glm::dvec3 position;

	double t;

	glm::dvec3 normal;

	std::shared_ptr<Material> material;

};

// std::ostream& operator << (std::ostream& o, Intersection const& intersection)
// 	  {
// 	  // o << "Position" << intersection.position[0] << " " << intersection.position[1] << " " << intersection.position[2] << std::endl;
// 	  o << "Position" << intersection.position[0] << std::endl;

// 	  return o;
// 	  }


#endif // BUW_INTERSECTION_HPP
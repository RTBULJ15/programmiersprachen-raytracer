# ifndef BUW_RAY_HPP
# define BUW_RAY_HPP

#include <glm/glm.hpp>

struct Ray
{	
	Ray(glm::dvec3 orig, glm::dvec3 dir) 
	: origin(orig)
	, direction(glm::normalize(dir))
	, direction_inv()
    {}
	
	glm::dvec3 cut_point(double t) const {
    return origin + t * direction;
    }
	
	friend Ray operator*(glm::dmat4 const& t, Ray const& ray){
    	return 
    	Ray(glm::dvec3(t * glm::dvec4(ray.origin, 1.0)),
      	glm::dvec3(t * glm::dvec4(ray.direction, 0.0)));
    }

	glm::dvec3 origin;
	glm::dvec3 direction;
	glm::vec3 direction_inv;
	// unsigned depth;
};

#endif
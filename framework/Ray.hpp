# ifndef BUW_RAY_HPP
# define BUW_RAY_HPP

#include <glm/glm.hpp>
#include <ostream>

struct Ray
{	
	Ray(glm::dvec3 orig, glm::dvec3 dir, unsigned d) 
	: origin(orig)
	, direction(glm::normalize(dir))
	, direction_inv()
    , depth(d)
    {}
	
	glm::dvec3 cut_point(double t) const {
    return origin + t * direction;
    }
	
	friend Ray operator*(glm::dmat4 const& t, Ray const& ray){
    	return Ray(
            glm::dvec3(t * glm::dvec4(ray.origin, 1.0)),
            glm::dvec3(t * glm::dvec4(ray.direction, 0.0)),
            ray.depth
        );
    }

    friend std::ostream& operator << (std::ostream& os, Ray const& ray) 
    {
    	os << "ray{";
    	os << "o(" << ray.origin.x << " " << ray.origin.y << " " << ray.origin.z << ")";
    	os << "d(" << ray.direction.x << " " << ray.direction.y << " " << ray.direction.z << ")";
    	os << "}";
    	return os;
    }

	glm::dvec3 origin;
	glm::dvec3 direction;
	glm::vec3 direction_inv;
	unsigned depth;
};

#endif
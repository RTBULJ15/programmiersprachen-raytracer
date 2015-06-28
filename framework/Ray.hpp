# ifndef BUW_RAY_HPP
# define BUW_RAY_HPP
#include <glm/vec3.hpp>

struct Ray
{	
	Ray(glm::vec3 orig, glm::vec3 dir) 
	: origin{orig}
	, direction(glm::normalize(dir))
    {}
	
	glm::vec3 origin;
	glm::vec3 direction;
};

#endif
#ifndef BUW_TRIANGLEBOX_HPP
#define BUW_TRIANGLEBOX_HPP
#include <glm/glm.hpp>

struct Trianglebox{
	Trianglebox(glm::vec3 v1_, glm::vec3 v2_, glm::vec3 v3_)
	: v1(v1_), v2(v2_), v3(v3_){}

	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 v3;

};

#endif
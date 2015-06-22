#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape{

	public:
		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max);

		float area() const;
		float volume() const;
		
		glm::vec3 getMin() const;
		glm::vec3 getMax() const;

	private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif
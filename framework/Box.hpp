#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>
#include "color.hpp"


class Box : public Shape{

	public:
		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color);

		/* virtual */ float area() const override;
		/* virtual */ float volume() const override;
		
		glm::vec3 getMin() const;
		glm::vec3 getMax() const;

		/* virtual */ void print(std::ostream&) const override;


	private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif
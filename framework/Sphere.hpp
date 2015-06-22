#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>


class Sphere : public Shape{
	public:
		Sphere();
		Sphere(glm::vec3 const& center, float radius);
		
		float area() const;
		float volume() const;

		glm::vec3 getcenter() const;
		float getradius() const;

		~Sphere();

	private:
		glm::vec3 center_;
		float radius_;

};

#endif
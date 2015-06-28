#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>
#include "color.hpp"
#include "Ray.hpp"
#include "intersection.hpp"

class Sphere : public Shape{
	public:
		Sphere();
		Sphere(glm::vec3 const& center, float radiusr, std::string name, Color color);
		
		/* virtual */ float area() const override;
		/* virtual */ float volume() const override;

		glm::vec3 getcenter() const;
		float getradius() const;

		Intersection intersect(Ray&) const&;

		/* virtual */ void print(std::ostream&) const override;
		~Sphere();

	private:
		glm::vec3 center_;
		float radius_;
	

};

#endif
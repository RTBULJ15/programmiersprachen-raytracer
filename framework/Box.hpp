#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <array>
#include "Shape.hpp"
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include "color.hpp"
#include "Box.hpp"
#include "intersection.hpp"
#include "Face.hpp"
#include "Triangle.hpp"
// #include "Trianglebox.hpp"


class Box : public Shape{
		// struct Color_B {
		// 	Color_B() : r(0.0), g(0.0), b(0.0) {}
		// 	Color_B(float red, float green, float blue) : r(red), g(green), b(blue) {}
		// 	float r;
		// 	float g;
		// 	float b;
		// };

		
	public:
		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Material const& material);

		/* virtual  float area() const override;
		 virtual  float volume() const override; */

		glm::vec3 getMin() const;
		glm::vec3 getMax() const;

		/* virtual */ void print(std::ostream&) const override;

		Intersection intersect(Ray const&) const override;


	private:
		glm::vec3 min_;
		glm::vec3 max_;

		std::array<Face, 6> faces_;


};

#endif

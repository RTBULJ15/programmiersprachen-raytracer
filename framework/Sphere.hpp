#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"
#include <glm/glm.hpp>
#include "color.hpp"
#include "Ray.hpp"
#include "intersection.hpp"

class Sphere : public Shape{
	public:
		Sphere();
		Sphere(std::string const& name, glm::dvec3 const& center, float radiusr, std::shared_ptr<Material> const& material);

		/* virtual  float area() const ;
		virtual  float volume() const override;*/

		glm::dvec3 getcenter() const;
		void setcenter_x(double centerx) &;
		void setcenter_y(double centery) &;
		void setcenter_z(double centerz) &;
		float getradius() const;
		void setradius(double radius) &;

		Intersection intersect(Ray const& ray) const override;

		/* virtual */ void print(std::ostream&) const override;

		glm::dvec3 kreisNormale(glm::dvec3 const& mittelpunkt, glm::dvec3 const& surface) const;
		
		~Sphere();

	private:
		glm::dvec3 center_;
		float radius_;


};

#endif

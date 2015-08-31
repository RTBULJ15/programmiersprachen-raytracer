#ifndef BUW_TRIANGLE_HPP
#define BUW_TRIANGLE_HPP

#include <array>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "Shape.hpp"
#include "Ray.hpp"
#include "intersection.hpp"


class Triangle : public Shape
{
	
		public:
			Triangle();
			Triangle(glm::dvec3 const& u, glm::dvec3 const& v, glm::dvec3 const& w);
			glm::dvec3 v1 () const;
			glm::dvec3 v2 () const;
			glm::dvec3 v3 () const;

			Intersection intersect (Ray const& ray) const override;
			glm::dvec3 barycentric_to_world (glm::dvec3 const& bary) const;

		private:
			glm::dvec3 v1_, v2_, v3_, n_;
			std::string name_;
			std::shared_ptr<Material> material_;
};

#endif

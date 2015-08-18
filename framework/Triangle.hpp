#ifndef BUW_TRIANGLE_HPP
#define BUW_TRIANGLE_HPP

#include <array>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include "Shape.hpp"
#include "Ray.hpp"
#include "intersection.hpp"


class Triangle : public Shape{
	
		public:
		
		Triangle();

		Triangle(glm::vec3 const& u, glm::vec3 const& v, glm::vec3 const& w);

			glm::vec3 v1 () const;

			glm::vec3 v2 () const;

			glm::vec3 v3 () const;


			Intersection intersect (Ray const& ray) const;



			glm::vec3 barycentric_to_world (glm::vec3 const& bary) const;

		private:
			glm::vec3 v1_, v2_, v3_, n_;
		};

#endif
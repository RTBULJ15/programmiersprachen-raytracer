// #ifndef BUW_BOX_HPP
// #define BUW_BOX_HPP

// #include <array>
// #include "Shape.hpp"
// #include <glm/vec3.hpp>
// #include <glm/gtx/intersect.hpp>
// #include "color.hpp"
// #include "Box.hpp"
// #include "intersection.hpp"
// #include "Face.hpp"
// #include "Triangle.hpp"
// #include "Trianglebox.hpp"


// class Box : public Shape{
	
// 	public:
//         Box();

//         Box(glm::vec3 const& p1, glm::vec3 const& p2, std::string name, std::shared_ptr<Material> const& material);
		
// 		//Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Material* const& material);

// 		glm::vec3 getMin() const;
// 		void setMin(glm::vec3 const& min);
// 		void setMinx(double const& minx);
// 		void setMiny(double const& miny);
// 		void setMinz(double const& minz);
// 		glm::vec3 getMax() const;
// 		void setMax(glm::vec3 const& max);
// 		void setMaxx(double const& maxx);
// 		void setMaxy(double const& maxy);
// 		void setMaxz(double const& maxz);

// 		/* virtual */ void print(std::ostream&) const override;

// 		/* virtual */ Intersection intersect(Ray const&) const override;
// 		~Box();

// 	private:
// 		glm::vec3 min_;
// 		glm::vec3 max_;
//        	std::string name_;
//         std::shared_ptr<Material> material_;
// 		std::array<Face, 6> faces_;


// };

// #endif

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <array>
#include "Shape.hpp"
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include "color.hpp"
#include "Box.hpp"
#include "intersection.hpp"



class Box : public Shape{
	
		class Triangle {
		public:
			Triangle() : v1_(), v2_(), v3_(), n_() {}

			Triangle(glm::vec3 const& u, glm::vec3 const& v, glm::vec3 const& w)
			 : v1_(u)
			 , v2_(v)
			 , v3_(w)
			 , n_(glm::normalize(glm::cross(v3_ - v1_, v2_ - v1_))) 
			{}

			glm::vec3 v1 () const {
				return v1_;
			}

			glm::vec3 v2 () const {
				return v2_;
			}

			glm::vec3 v3 () const {
				return v3_;
			}


			Intersection intersect (Ray const& ray) const {
				glm::vec3 bary;
				Intersection isec;

				isec.hit = glm::intersectRayTriangle (
					ray.origin, ray.direction, 
					v1_, v2_, v3_, 
					bary
				);

				if (isec.hit) {
					isec.normal = n_;
					isec.position = barycentric_to_world(bary);
					isec.t = glm::length(isec.position - ray.origin);
				}

				return isec;
			}

			glm::vec3 barycentric_to_world (glm::vec3 const& bary) const {
				glm::vec3 result;
		        double u, v, w;

		        u = bary.x;
		        v = bary.y;
		        w = 1 - (u+v);

		        result.x = (u * v1_.x + v * v2_.x + w * v3_.x);
		        result.y = (u * v1_.y + v * v2_.y + w * v3_.y);
		        result.z = (u * v1_.z + v * v2_.z + w * v3_.z);

		        return result;
			}

		private:
			glm::vec3 v1_, v2_, v3_, n_;
		};

		class Face {
		public:

			Face() : t1_(), t2_() {}
 			Face(Triangle const& a, Triangle const& b) : t1_(a), t2_(b) {}

 			Intersection intersect(Ray const& ray) const {
 				auto isec1 = t1_.intersect(ray);
 				auto isec2 = t2_.intersect(ray);

 				if (isec1.hit && isec2.hit) {
 					if (isec1.t < isec2.t) {
 						return isec1;
 					} else {
 						return isec2;
 					}
 				} else if (isec1.hit) {
 					return isec1;
 				} else if (isec2.hit) {
 					return isec2;
 				}

 				return Intersection();
 			}

 		private:
			Triangle t1_, t2_;
			// Color c;
		};

	public:
		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, std::shared_ptr<Material> const& material);

		// /* virtual */ float area() const override;
		// /* virtual */ float volume() const override;
		
		glm::vec3 getMin() const;
		glm::vec3 getMax() const;

		void setMin(glm::vec3 const& max);
		void setMinx(double const& maxx);
		void setMiny(double const& maxy);
		void setMinz(double const& maxz);
 		void setMax(glm::vec3 const& max);
		void setMaxx(double const& maxx);
		void setMaxy(double const& maxy);
		void setMaxz(double const& maxz);

		/* virtual */ void print(std::ostream&) const override;

		Intersection intersect(Ray const&) const override;

		~Box();

	private:
		glm::vec3 min_;
		glm::vec3 max_;

		std::array<Face, 6> faces_;


};

#endif
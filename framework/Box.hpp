// #ifndef BUW_BOX_HPP
// #define BUW_BOX_HPP

// #include <array>
// #include "Shape.hpp"
// #include <glm/dvec3.hpp>
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

//         Box(glm::dvec3 const& p1, glm::dvec3 const& p2, std::string name, std::shared_ptr<Material> const& material);
		
// 		//Box(glm::dvec3 const& min, glm::dvec3 const& max, std::string name, Material* const& material);

// 		glm::dvec3 getMin() const;
// 		void setMin(glm::dvec3 const& min);
// 		void setMinx(double const& minx);
// 		void setMiny(double const& miny);
// 		void setMinz(double const& minz);
// 		glm::dvec3 getMax() const;
// 		void setMax(glm::dvec3 const& max);
// 		void setMaxx(double const& maxx);
// 		void setMaxy(double const& maxy);
// 		void setMaxz(double const& maxz);

// 		/* virtual */ void print(std::ostream&) const override;

// 		/* virtual */ Intersection intersect(Ray const&) const override;
// 		~Box();

// 	private:
// 		glm::dvec3 min_;
// 		glm::dvec3 max_;
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

			Triangle(glm::dvec3 const& u, glm::dvec3 const& v, glm::dvec3 const& w)
			 : v1_(u)
			 , v2_(v)
			 , v3_(w)
			 , n_(-glm::normalize(glm::cross(v3_ - v1_, v2_ - v1_))) 
			{}

			glm::dvec3 v1 () const {
				return v1_;
			}

			glm::dvec3 v2 () const {
				return v2_;
			}

			glm::dvec3 v3 () const {
				return v3_;
			}

			glm::dvec3 n() const {
				return n_;
			}


			Intersection intersect (Ray const& ray) const {
				glm::dvec3 bary;
				Intersection isec;

				isec.hit = glm::intersectRayTriangle (
					ray.origin, ray.direction, 
					v1_, v2_, v3_, 
					bary
				);

				if (isec.hit) {
					isec.normal = n_;
					isec.position = barycentric_to_world(bary);
					isec.t = bary.z;
				}

				return isec;
			}

			glm::dvec3 barycentric_to_world (glm::dvec3 const& bary) const {
				glm::dvec3 result;
		        double u, v, w;

		        u = 1 - (bary.x + bary.y);
		        v = bary.x;
		        w = bary.y;

		        return u * v1_ + v * v2_ + w * v3_;
			}

		private:
			glm::dvec3 v1_, v2_, v3_, n_;
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
		Box(std::string const& name, glm::dvec3 const& min, glm::dvec3 const& max, std::shared_ptr<Material> const& material);

		// /* virtual */ float area() const override;
		// /* virtual */ float volume() const override;
		
		glm::dvec3 getMin() const;
		glm::dvec3 getMax() const;

		void setMin(glm::dvec3 const& max);
		void setMinx(double const& maxx);
		void setMiny(double const& maxy);
		void setMinz(double const& maxz);
 		void setMax(glm::dvec3 const& max);
		void setMaxx(double const& maxx);
		void setMaxy(double const& maxy);
		void setMaxz(double const& maxz);

		/* virtual */ void print(std::ostream&) const override;

		Intersection intersect(Ray const&) const override;

		~Box();

	private:
		glm::dvec3 min_;
		glm::dvec3 max_;

		std::array<Face, 6> faces_;


};

#endif
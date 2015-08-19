#ifndef BUW_FACE_HPP
#define BUW_FACE_HPP

#include "Triangle.hpp"

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

#endif
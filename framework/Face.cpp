#include "Face.hpp"

			Face::Face() : 
			Shape{}
			,name_("") 
			,material_()
			,t1_(), t2_() {}
			
			Face::Face(Triangle const& a, Triangle const& b) 
			: Shape{"Gesicht"}
			,t1_(a)
			, t2_(b)
			, name_{}
			, material_{} {}
 			
 			Face::Face(std::string const& name, std::shared_ptr<Material> const& material,
 						Triangle const& a, Triangle const& b) 
 			: Shape{}
			 , name_(name), material_(material) 
			 , t1_(a), t2_(b) {}

 			Intersection Face::intersect(Ray const& ray) const {
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

 

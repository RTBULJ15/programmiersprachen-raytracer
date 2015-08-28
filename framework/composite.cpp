#include "composite.hpp"

Composite::Composite() : 
  Shape(), child_vec(){}


 void Composite::add_child(std::shared_ptr<Shape> const& child){
   child_vec_.push_back(child);
 }


Intersection Composite::intersect(Ray const& r) const{
	
// child_vec durchgehen und niedrigstes t finden
// Ray r von Kamera 

  float min_t = 9999.0f; 
  
  Intersection i;
  for (auto const& child: child_vec_) {
    auto current_i = child->intersect_with(ray);
	if (current_i.hit && current_i.t > 0 && current_i.t < min_t) {
		i = current_i;
		min_t = current_i.t;
	}
  }
	return i;
}

 Composite::~Composite(){std::cout << "~composite destructor called" << std::endl;}
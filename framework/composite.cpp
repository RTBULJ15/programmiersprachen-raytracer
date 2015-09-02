#include "composite.hpp"

Composite::Composite() : 
  Shape(), child_vec_(){}

Composite::Composite(Composite const& rhs)
 : Shape(rhs), child_vec_()
{
  for (auto c: rhs.child_vec_) {
    child_vec_.push_back(c->clone());
  }
}

std::shared_ptr<Shape>
Composite::clone () const 
{
  return std::make_shared<Composite>(*this);
}


 void Composite::add_child(std::shared_ptr<Shape> const& child){
   child_vec_.push_back(child);
 }

std::vector<std::shared_ptr<Shape>> const& Composite::get_child_vec(){
return child_vec_;}

Intersection Composite::intersect(Ray const& ray) const{
	
// child_vec durchgehen und niedrigstes t finden
// Ray r von Kamera 

  Ray r = object_ray(ray);

  float min_t = 9999.0f; 
  
  Intersection i;
  for (auto const& child: child_vec_) {
    auto current_i = child->intersect(r);
  	if (current_i.hit && current_i.t > 0 && current_i.t < min_t) {
  		i = current_i;
  		min_t = current_i.t;
  	}
  }
	return i;
}

void Composite::print(std::ostream& os) const {
  os << "{Composite" << " ";
  for (auto c: child_vec_) {
    c->print(os);
  }
  os << "}";
}

 Composite::~Composite(){}
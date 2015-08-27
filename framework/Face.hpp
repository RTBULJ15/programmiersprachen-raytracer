#ifndef BUW_FACE_HPP
#define BUW_FACE_HPP

#include "Triangle.hpp"

class Face : public Shape 
{
public:
			Face();
 			Face(Triangle const& a, Triangle const& b);
 			Face(std::string const& name, std::shared_ptr<Material> const& material,
 						Triangle const& a, Triangle const& b);
 			
 			
 			Intersection intersect(Ray const& ray) const;

private:
			Triangle t1_;
 			Triangle t2_;
 			std::string name_;
 			std::shared_ptr<Material> material_;

};
#endif

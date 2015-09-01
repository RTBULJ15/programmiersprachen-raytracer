#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "Material.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "Ray.hpp"
#include "intersection.hpp"
#include <memory>
#include <vector>

#define GLM_SWIZZLE
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

class Shape{
public:
	Shape ();
	Shape (std::string const& name);
	Shape (std::string const& name, std::shared_ptr<Material> const& material);

	virtual Intersection intersect(Ray const& ray) const = 0; //pure virtual

	std::string const& name() const;
	void name(std::string x);
	
	std::shared_ptr<Material> const& getMaterial() const;
	void setMaterial(std::shared_ptr<Material> mat);

	void translate(glm::dvec3 const& t);
  	void scale(glm::dvec3 const& s);
  	void rotate(double deg, glm::dvec3 const& axis);

	virtual void print(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		s.print(os);
		return os;
	}

	virtual ~Shape();

protected:
	Ray object_ray(Ray const& r) const;
    glm::dvec3 world_normal(glm::dvec3 const& n) const;
  	
  	std::string name_;
	std::shared_ptr<Material> material_;

	// object to world space and inverse
  	glm::dmat4 world_transform_;
  	glm::dmat4 world_transform_inv_;

  	// transposed transformations
  	glm::dmat3 world_transform_T_;
  	glm::dmat3 world_transform_inv_T_;

};




#endif

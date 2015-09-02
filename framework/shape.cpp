#include "Shape.hpp"
#include <memory>
#include <vector>

	Shape::Shape ()
	: name_{"default"}, material_{}
	{}

	Shape::Shape (Shape const& rhs) 
	 : name_(rhs.name_)
	 , material_(rhs.material_)
	 , world_transform_(rhs.world_transform_)
	 , world_transform_inv_(rhs.world_transform_inv_)
	 , world_transform_T_(rhs.world_transform_T_)
	 , world_transform_inv_T_(rhs.world_transform_inv_T_)
	{}

	Shape::Shape (std::string const& name) 
	: name_{name}, material_{}
	, world_transform_(), world_transform_inv_()
  	, world_transform_T_(), world_transform_inv_T_()
	{}
	Shape::Shape (std::string const& name, std::shared_ptr<Material> const& material)
	: name_(name), material_(material)
	, world_transform_(), world_transform_inv_()
  	, world_transform_T_(), world_transform_inv_T_()
	{}

	Shape::~Shape()
    	{
    	}

	std::string const& Shape::name() const{return name_;}
	void Shape::name(std::string x) {name_ = x;}

	std::shared_ptr<Material> const& Shape::getMaterial() const{return material_;}
        void Shape::setMaterial(std::shared_ptr<Material> mat) {material_ = mat;}

	void Shape::print(std::ostream& os) const {
		os<<"Name: "<<name_<<", Material: "<<material_<<std::endl;

	}

	void Shape::translate(glm::dvec3 const& t)
	{
	  auto m = glm::translate(glm::dmat4(), t);
	  auto m_inv = glm::translate(glm::dmat4(), -t);

	  world_transform_ = m * world_transform_;
	  world_transform_inv_ = world_transform_inv_ * m_inv;

	  world_transform_T_ = glm::transpose(glm::dmat3(world_transform_));
	  world_transform_inv_T_ = glm::transpose(glm::dmat3(world_transform_inv_));

	  }
	
	void Shape::rotate(double rad, glm::dvec3 const& axis)
	{
	  auto m = glm::rotate(glm::dmat4(), rad, axis);
	  auto m_inv = glm::rotate(glm::dmat4(), -rad, axis);

	  world_transform_ = m * world_transform_;
	  world_transform_inv_ = world_transform_inv_ * m_inv;

	  world_transform_T_ = glm::transpose(glm::dmat3(world_transform_));
	  world_transform_inv_T_ = glm::transpose(glm::dmat3(world_transform_inv_));

	}

	void Shape::scale(glm::dvec3 const& s)
	{
	  auto m = glm::scale(glm::dmat4(), s);
	  auto m_inv = glm::scale(glm::dmat4(), glm::dvec3(1.0f / s.x, 1.0f / s.y, 1.0f / s.z));

	  world_transform_ = m * world_transform_;
	  world_transform_inv_ = world_transform_inv_ * m_inv;

	  world_transform_T_ = glm::transpose(glm::dmat3(world_transform_));
	  world_transform_inv_T_ = glm::transpose(glm::dmat3(world_transform_inv_));

	}

	glm::dvec3 Shape::world_normal(glm::dvec3 const& n) const
	{
	  return glm::normalize(world_transform_inv_T_ * n);
	}

	Ray Shape::object_ray(Ray const& r) const
	{
	  return world_transform_inv_ * r;
	}

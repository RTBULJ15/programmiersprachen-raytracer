#include "Shape.hpp"
#include <memory>
#include <vector>

	Shape::Shape ()
	: name_{"default"}, material_{}
	{}

	Shape::Shape (std::string const& name, std::shared_ptr<Material> const& material)
	: name_(name), material_(material)
	{}

	Shape::~Shape()
    	{
        std::cout << "~Shape destructor called" << std::endl;
    	}

	std::string const& Shape::getName() const{return name_;}
	void Shape::setName(std::string x) {name_ = x;}

	std::shared_ptr<Material> const& Shape::getMaterial() const{return material_;}
        void Shape::setMaterial(std::shared_ptr<Material> mat) {material_ = mat;}

	void Shape::print(std::ostream& os) const {
		os<<"Name: "<<name_<<", Material: "<<material_<<std::endl;

	}

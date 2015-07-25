#include "Shape.hpp"

	Shape::Shape ()
	: name_{"default"}, material_{}
	{}

	Shape::Shape (std::string const& name, Material const& material)
	: name_(name), material_(material)
	{}

	Shape::~Shape()
    {
        std::cout << "~Shape destructor called" << std::endl;
    }

	std::string const& Shape::getName() const{return name_;}
	Material const& Shape::getMaterial() const{return material_;}

	void Shape::print(std::ostream& os) const { 
		os<<"Name: "<<name_<<", Material: "<<material_<<std::endl;
		
	}

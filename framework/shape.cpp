#include "Shape.hpp"

	Shape::Shape ()
	: name_{"default"}, color_{0,0,0}
	{}

	Shape::Shape (std::string name, Color color)
	: name_(name), color_(color)
	{}

	Shape::~Shape()
    {
        std::cout << "~Shape destructor called" << std::endl;
    }

	void Shape::setName(std::string const& name) {name_=name;}
	void Shape::setColor(Color const& colorSphere){color_=colorSphere;}

	void Shape::print(std::ostream& os) const { 
		os<<"Name: "<<name_<<", Color: "<<color_<<std::endl;
		
	}

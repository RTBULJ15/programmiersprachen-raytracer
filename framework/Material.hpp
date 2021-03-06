# ifndef BUW_MATERIAL_HPP
# define BUW_MATERIAL_HPP
#include "color.hpp"
#include <glm/vec3.hpp>
#include <string>

struct Material
{	
	Material()
	 : name()
	 , ka() 
	 , kd() 
	 , ks() 
	 , specular_exp(1.0)
    {}

    Material(std::string const& matname, Color const& ambient, Color const& diffuse, Color const& specular, double specular_exponent)
	 : name(matname)
	 , ka(ambient)
	 , kd(diffuse)
	 , ks(specular)
	 , specular_exp(specular_exponent)
    {}

    friend std::ostream& operator<<(std::ostream& os, Material const& m)
	{
		os << "{Material ";
		os << m.name << " ";
		os << m.ka << " ";
		os << m.kd << " ";
		os << m.ks << " ";
		os << m.specular_exp << " ";
		os << "}";
		return os;
	}

	
	std::string name;
	Color ka;
	Color kd;
	Color ks;
	double specular_exp;
};

#endif
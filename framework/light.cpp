#include "light.hpp"

    Light::Light()
    :	position_(), ka_(), kd_()
    {};

    Light::Light(std::string const& name, glm::dvec3 const& position, Color const& ka , Color const& kd)
    : name_(name), position_(position), ka_(ka), kd_(kd)
    {};

    glm::dvec3 Light::position() const
    {
    	return position_;
    };

    std::string
    Light::name () const 
    {
    	return name_;
    }

	Color
	Light::ambient () const 
	{
		return ka_;
	}

	Color 
	Light::diffuse () const 
	{
		return kd_;
	}

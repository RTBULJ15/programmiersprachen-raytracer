#include "light.hpp"

    Light::Light()
    :	position_(), ka_(), kd_()
    {};

    Light::Light(Light const& rhs) 
    : name_(rhs.name_), position_(rhs.position_), ka_(rhs.ka_), kd_(rhs.kd_)
    {}

    Light::Light(std::string const& name, glm::dvec3 const& position, Color const& ka , Color const& kd)
    : name_(name), position_(position), ka_(ka), kd_(kd)
    {};

    std::shared_ptr<Light>
    Light::clone () const 
    {
        return std::make_shared<Light>(*this);
    }

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

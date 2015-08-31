#include "light.hpp"

    Light::Light()
    :	position_(), ka_(), kd_()
    {};

    Light::Light(std::string const& name, glm::dvec3 const& position, glm::dvec3 const& ka , glm::dvec3 const& kd)
    : name_(name), position_(position), ka_(ka), kd_(kd)
    {};

    glm::dvec3 Light::getPos() const
    {
    	return position_;
    };


	void Light::setName (std::string name) &
	{
	    name_ = name;
	};

	void Light::setPosition_x(double const& posx) &
	{
	    position_[0] = posx;
	};

	void Light::setPosition_y(double const& posy) &
	{
	    position_[1] = posy;
	};

	void Light::setPosition_z(double const& posz) &
	{
	    position_[2] = posz;
	};
	float Light::getPos_x() const{
		return position_[0];
	}

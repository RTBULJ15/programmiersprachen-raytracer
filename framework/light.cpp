#include "light.hpp"

    Light::Light()
    :	position_(), ka_(), kd_()
    {};

    Light::Light(std::string const& name, glm::vec3 const& position, glm::vec3 const& ka , glm::vec3 const& kd)
    : name_(name), position_(position), ka_(ka), kd_(kd)
    {};

    glm::vec3 Light::getPos() const
    {
    	return position_;
    };


	/*void Light::setName (std::string name) &
	{
	    name_ = name;
	};

	void Light::setPosition_x(double const& posx) &
	{
	    position_.x = posx;
	};

	void Light::setPosition_y(double const& posy) &
	{
	    position_.y = posy;
	};

	void Light::setPosition_z(double const& posz) &
	{
	    position_.z = posz;
	};*/

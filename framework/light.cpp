#include <iostream>
#include <string>
#include "light.hpp"

Light::Light()
{

}

/*Light(std::string name, glm::vec3 position, Color kd , Color ks);
{

}*/

void Light::setName (std::string name)
{
    name_ = name;
}

void Light::setPosition_x(double posx)
{
    position_.x = posx;
}

void Light::setPosition_y(double posy)
{
    position_.y = posy;
}

void Light::setPosition_z(double posz)
{
    position_.z = posz;
}

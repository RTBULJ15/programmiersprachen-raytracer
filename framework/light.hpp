# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP
 
# include "glm/vec3.hpp"
# include <string>


class Light
{
public:
    Light();
    Light(std::string const& name, glm::vec3 const& position, glm::vec3 const& ka , glm::vec3 const& kd);
    void setName(std::string name)  &;
    void setPosition_x(double const& posx) &;
    void setPosition_y(double const& posy) &;
    void setPosition_z(double const& posz) &;
    glm::vec3 getPos() const; 

private:
    glm::vec3 position_;
    std::string name_;

    glm::vec3 ka_;
    glm::vec3 kd_;
};

#endif

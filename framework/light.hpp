# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP

# include "glm/glm.hpp"
# include <string>


class Light
{
public:
    Light();
    Light(std::string const& name, glm::dvec3 const& position, glm::dvec3 const& ka , glm::dvec3 const& kd);
    glm::dvec3 getPos() const;
    void setName(std::string name)  &;
    void setPosition_x(double const& posx) &;
    void setPosition_y(double const& posy) &;
    void setPosition_z(double const& posz) &;
    float getPos_x() const;


private:
    glm::dvec3 position_;
    std::string name_;

    glm::dvec3 ka_;
    glm::dvec3 kd_;
};

#endif

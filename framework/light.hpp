# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP

# include "color.hpp"
# include "glm/vec3.hpp"

class Light
{
public:
    Light(){};
    Light(std::string name, glm::vec3 position/*, Color kd , Color ks*/){};
    void setName (std::string name){};
    void setPosition_x(double posx){};
    void setPosition_y(double posy){};
    void setPosition_z(double posz){};



private:
    std::string name_;
    glm::vec3 position_;
    //
    /*Color kd;
    Color ks;*/
};

#endif

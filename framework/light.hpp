# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP

# include "color.hpp"
# include "glm/vec3.hpp"

class Light
{
public:
    Light();
    Light(glm::vec3 position, Color ka , Color kd , Color ks);

private:
    glm::vec3 position;
    Color ka;
    Color kd;
    Color ks;
};

#endif

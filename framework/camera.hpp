# ifndef BUW_CAMERA_HPP
# define BUW_CAMERA_HPP

#include <glm/vec3.hpp>

class Camera
{
public:
    Camera();
    Camera(double horizontal_apex_angle, glm::ivec2 resolution);

private:
    double horizontal_apex_angle;
    glm::ivec2 resolution;
};

#endif

# ifndef BUW_CAMERA_HPP
# define BUW_CAMERA_HPP

#include <iostream>
#include <string>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

class Camera
{
public:
    Camera();
    Camera(std::string name,double horizontal_apex_angle, glm::ivec2 resolution);
    void setname(std::string name);
    void setangle(double angle);
    void setResolution_x(double resx);
    void setResolution_y(double resy);

private:
    std::string name_;
    double horizontal_apex_angle;
    glm::ivec2 resolution;
};

#endif

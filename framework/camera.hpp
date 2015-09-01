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
    Camera(std::string const& name, double horizontal_apex_angle);
    void setname(std::string const& name);
    std::string name () const;
    void setangle(double angle);
    double focallength () const;
    double fov_to_fl() const;

private:
    std::string name_;
    double focal_length_;
};

#endif

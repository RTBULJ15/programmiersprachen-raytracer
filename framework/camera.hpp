# ifndef BUW_CAMERA_HPP
# define BUW_CAMERA_HPP

#include <iostream>
#include <string>
#include <glm/vec3.hpp>
#include "Ray.hpp"

#include <glm/glm.hpp>

#define GLM_SWIZZLE
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

class Camera
{
public:
    Camera();
    Camera(Camera const& rhs);
    Camera(std::string const& name, double horizontal_apex_angle, glm::dvec3 const& eye, 
        glm::dvec3 const& dir, glm::dvec3 const& up);
    std::shared_ptr<Camera> clone () const;
    void setname(std::string const& name);
    std::string name () const;
    void setangle(double angle);
    double focallength () const;
    double fov_to_fl() const;
    void translate(glm::dvec3 const& t);
    void rotate(double rad, glm::dvec3 const& axis);
    Ray generateRay(glm::dvec2 const& viewPlaneCoord, int const rayD) const;

    friend std::ostream& operator << (std::ostream& os, Camera const& c) {
        os << "{Camera ";
        os << c.name_ << " ";
        os << c.focal_length_ << " ";
        os << "}";
        return os;
    }

private:
    std::string name_;
    double focal_length_;
    
    glm::dmat4 world_transform_;
    glm::dmat4 world_transform_inv_;
};

#endif

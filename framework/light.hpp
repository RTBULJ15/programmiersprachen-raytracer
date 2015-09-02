# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP

# include "glm/glm.hpp"
# include <string>
# include "color.hpp"
#include <memory>
#include <ostream>

class Light
{
public:
    Light();
    Light(Light const& rhs);
    Light(std::string const& name, glm::dvec3 const& position, Color const& ka , Color const& kd);
    std::shared_ptr<Light> clone () const;
    glm::dvec3 position() const;
    Color ambient () const;
    Color diffuse () const;
    std::string name() const;

    friend std::ostream& operator << (std::ostream& os, Light const& l) {
        os << "{Light ";
        os << l.name_ << " ";
        os << "{p " << l.position_.x << " " << l.position_.y << " " << l.position_.z << " ";
        os << l.ka_ << " ";
        os << l.kd_ << " ";
        os << "}";
        return os;
    }

private:
    glm::dvec3 position_;
    std::string name_;

    Color ka_;
    Color kd_;
};

#endif

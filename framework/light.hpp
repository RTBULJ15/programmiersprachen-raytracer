# ifndef BUW_LIGHT_HPP
# define BUW_LIGHT_HPP

# include "glm/glm.hpp"
# include <string>
# include "color.hpp"


class Light
{
public:
    Light();
    Light(std::string const& name, glm::dvec3 const& position, Color const& ka , Color const& kd);
    glm::dvec3 position() const;
    Color ambient () const;
    Color diffuse () const;
    std::string name() const;

private:
    glm::dvec3 position_;
    std::string name_;

    Color ka_;
    Color kd_;
};

#endif

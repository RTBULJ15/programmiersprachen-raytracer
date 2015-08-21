# ifndef BUW_RAYCASTER_HPP
# define BUW_RAYCASTER_HPP

#include <glm/vec3.hpp>
#include "color.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "intersection.hpp"
#include "image.hpp"
#include "pixel.hpp"

class Raycaster
{
public:
    Raycaster();
    Raycaster(Camera const& camera, Scene const& scene);
    Image render();
    Intersection trace (Ray traceray);
    Pixel shade(Ray pixelray, Intersection pixelisec);

private:
    Camera camera_;
    Scene scene_;

};

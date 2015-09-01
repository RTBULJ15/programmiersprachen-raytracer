#ifndef BUW_RAYCASTER_HPP
#define BUW_RAYCASTER_HPP

#define RAY_EPSILON 1e-6

#include <glm/vec3.hpp>
#include "color.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "intersection.hpp"
#include "image.hpp"
#include "pixel.hpp"
#include "Ray.hpp"

class Raycaster
{
public:
    Raycaster();
    Raycaster(std::shared_ptr<Scene> const& scene);
    Intersection trace(Ray const& ray);
    Color shade(Ray const& ray, Intersection const& isec);

private:
    std::shared_ptr<Scene> scene_;
};

#endif
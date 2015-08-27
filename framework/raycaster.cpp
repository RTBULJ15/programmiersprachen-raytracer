#include "raycaster.hpp"

Raycaster::Raycaster()
:camera_{}, scene_{}
{}

Raycaster::Raycaster(Camera const& camera, Scene const& scene)
:camera_(camera),scene_(scene)
{}

Image Raycaster::render()
{

}

Intersection Raycaster::trace (Ray traceray)
{

}

Pixel Raycaster::shade(Ray pixelray, Intersection pixelisec)
{

}

#ifndef BUW_IMAGE_HPP
#define BUW_IMAGE_HPP

#include <glm/vec3.hpp>
#include "color.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "intersection.hpp"
#include "image.hpp"
#include "pixel.hpp"


class Image
{
public:
    Image();
    Image(std::vector<Pixel> pixels, glm::ivec2 resolution);
    void setPixel(Pixel pixel);
   // std::vector pixels();
    glm::ivec2 resolution();

private:
    std::vector<Pixel> pixels_;
    glm::ivec2 resolution_;
};

#endif
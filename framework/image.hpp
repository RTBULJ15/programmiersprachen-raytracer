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
    Image(glm::ivec2 const& resolution);
    void setPixel(Pixel const& pixel);
   // std::vector pixels();
    glm::ivec2 resolution() const;
	const std::vector<Color>& colorbuffer() const;
  
private:
    std::vector<Color> colorbuffer_;
    glm::ivec2 resolution_;
};

#endif
#include "image.hpp"

Image::Image()
:colorbuffer_{},resolution_{}
{}

Image::Image(glm::ivec2 const& resolution)
:colorbuffer_(std::vector<Color>(resolution.x * resolution.y)), resolution_(resolution)
{}

void Image::setPixel(Pixel const& pixel)
{
	colorbuffer_[pixel.x + pixel.y * resolution_.x] = pixel.color;
}

// std::vector Image::pixels()
// {

// }

glm::ivec2 
Image::resolution() const
{
	return resolution_;
}

const std::vector<Color>& 
Image::colorbuffer() const
{
	return colorbuffer_;    
}


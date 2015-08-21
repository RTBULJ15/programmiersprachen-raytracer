

Image::Image()
:pixels{},resolution{}
{}

Image::Image(std::vector<Pixel> pixels, glm::ivec2 resolution)
:pixels_(pixels),resolution_(resolution)
{}

void Image::setPixel(Pixel pixel)
{

}

std::vector Image::pixels()
{

}

glm::ivec2 Image::resolution()
{

}

#include "imagewriter.hpp"

ImageWriter::ImageWriter (Image const& img)
 : ppm_(img.resolution().x, img.resolution().y)
{
	for (int x=0; x<img.resolution().x; ++x){
		for (int y=0; y<img.resolution().y; ++y) {
			ppm_.write(Pixel(x, y, img.colorbuffer()[x + y*img.resolution().x]));
		}
	}
}

void
ImageWriter::write (std::string const& path)
{
	ppm_.save(path);
}
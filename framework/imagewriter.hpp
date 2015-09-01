#ifndef BUW_IMAGEWRITER_HPP
#define BUW_IMAGEWRITER_HPP

#include "image.hpp"
#include <string>

class ImageWriter
{
public:
	ImageWriter(Image const& img);
	void write (std::string const& path);
private:
	PpmWriter ppm_;
};

#endif // BUW_IMAGEWRITER_HPP
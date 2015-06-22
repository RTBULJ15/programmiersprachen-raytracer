#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>

class Shape{

public:
	virtual float area() const = 0;

	virtual float volume() const = 0;

private:


};




#endif 
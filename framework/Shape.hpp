#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "Ray.hpp"

class Shape{

public:
	Shape ();
	Shape (std::string, Color);

	virtual float area() const = 0;

	virtual float volume() const = 0;


	void setName(std::string const&);
	void setColor(Color const&);


	virtual void print(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		s.print(os);
		return os;
	}

	virtual ~Shape();

protected:
	std::string name_;
	Color color_;

};




#endif 
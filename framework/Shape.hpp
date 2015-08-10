#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "Material.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "Ray.hpp"
#include "intersection.hpp"

class Shape{

public:
	Shape ();
	Shape (std::string const& name, Material const& material);

	virtual Intersection intersect(Ray const& ray) const = 0; //pure virtual

	//virtual float area() const = 0;

	//virtual float volume() const = 0;


	std::string const& getName() const;
	Material const& getMaterial() const;


	virtual void print(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		s.print(os);
		return os;
	}

	virtual ~Shape();

protected:
	std::string name_;
	Material material_;

};




#endif

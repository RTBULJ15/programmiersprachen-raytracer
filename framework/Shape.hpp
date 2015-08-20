#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "Material.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "Ray.hpp"
#include "intersection.hpp"
#include <memory>
#include <vector>

class Shape{

public:
	Shape ();
	Shape (std::string const& name, std::shared_ptr<Material> const& material);

	virtual Intersection intersect(Ray const& ray) const = 0; //pure virtual

	//virtual float area() const = 0;

	//virtual float volume() const = 0;


	std::string const& getName() const;
	void setName(std::string x);
	std::shared_ptr<Material> const& getMaterial() const;
	void setMaterial(std::shared_ptr<Material> mat);



	virtual void print(std::ostream& os) const;

	friend std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		s.print(os);
		return os;
	}

	virtual ~Shape();

protected:
	std::string name_;
	std::shared_ptr<Material> material_;

};




#endif

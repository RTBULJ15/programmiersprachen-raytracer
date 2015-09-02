# ifndef BUW_COMPOSITE_HPP
# define BUW_COMPOSITE_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>

class Composite : public Shape{
	public: 
		Composite();
		Composite(Composite const& rhs);

		/* virtual */ std::shared_ptr<Shape> clone() const override;

        void add_child(std::shared_ptr<Shape> const& child);
        Intersection intersect(Ray const& ray) const override;
        std::vector<std::shared_ptr<Shape>> const& get_child_vec();
        
        /* virtual */ void print(std::ostream& os) const override;

        ~Composite();

    private: 
    	std::vector<std::shared_ptr<Shape>> child_vec_;

};

#endif

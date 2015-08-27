// #include "Box.hpp"
// #include "color.hpp"
// #include <glm/gtx/intersect.hpp>
// #include "Triangle.hpp"
// #include "Face.hpp"
// // TODO: anpassen
// Box::Box()
//   : Shape{}, min_(0,0,0), max_(0,0,0), faces_()
//   {}


// Box::Box(glm::vec3 const& p1, glm::vec3 const& p2, std::string name, std::shared_ptr<Material> const& material)
//   : Shape(name, material)
//   , min_(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z))
//   , max_(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z))
//   , faces_()
// {
// 	glm::vec3 ldf (min_.x, min_.y, min_.z);
// 	glm::vec3 ldb (min_.x, min_.y, max_.z);
// 	glm::vec3 luf (min_.x, max_.y, min_.z);
// 	glm::vec3 lub (min_.x, max_.y,max_.z);
// 	glm::vec3 rdf (max_.x, min_.y, min_.z);
// 	glm::vec3 rdb (max_.x, min_.y, max_.z);
// 	glm::vec3 ruf (max_.x, max_.y, min_.z);
// 	glm::vec3 rub (max_.x, max_.y,max_.z);

// 	// front face
// 	Triangle front_t1(rdf, ldf, ruf);
// 	Triangle front_t2(ruf, ldf, luf);
// 	Face front(front_t1, front_t2);

// 	// back face
// 	Triangle back_t1(ldb, rdb, rub);
// 	Triangle back_t2(ldb, rub, lub);
// 	Face back(back_t1, back_t2);

// 	// up face
// 	Triangle up_t1(ruf, luf, rub);
// 	Triangle up_t2(rub, luf, lub);
// 	Face up(up_t1, up_t2);

// 	// down face
// 	Triangle down_t1(ldf, rdf, rdb);
// 	Triangle down_t2(ldf, rdb, ldb);
// 	Face down(down_t1, down_t2);

// 	// left face
// 	Triangle left_t1(luf, ldf, lub);
// 	Triangle left_t2(lub, ldf, ldb);
// 	Face left(left_t1, left_t2);

// 	// right face
// 	Triangle right_t1(rdf, ruf, rub);
// 	Triangle right_t2(rdf, rub, rdb);
// 	Face right(right_t1, right_t2);

// 	faces_[0] = front;
// 	faces_[1] = back;
// 	faces_[2] = left;
// 	faces_[3] = right;
// 	faces_[4] = up;
// 	faces_[5] = down;
// }



// glm::vec3 Box::getMin() const{
// 	return min_;
// }
// void Box::setMin(glm::vec3 const& min)
// {
//     min_ = min;
// }
// void Box::setMinx(double const& minx)
// {
//     min_.x = minx;
// }
// void Box::setMiny(double const& miny)
// {
//     min_.y = miny;
// }
// void Box::setMinz(double const& minz)
// {
//     min_.z = minz;
// }
// glm::vec3 Box::getMax() const{
// 	return max_;
// }
// void Box::setMax(glm::vec3 const& max)
// {
//     max_ = max;
// }
// void Box::setMaxx(double const& maxx)
// {
//     max_.x = maxx;
// }
// void Box::setMaxy(double const& maxy)
// {
//     max_.y = maxy;
// }
// void Box::setMaxz(double const& maxz)
// {
//     max_.z = maxz;
// }

// void Box::print(std::ostream& os) const{
// 	Shape::print(os);
// 	os << "MinVec: " << min_.x << min_.y << min_.z;
// 	os << " MaxVec: " << max_.x << max_.y << max_.z;
// }

// Intersection Box::intersect(Ray const& ray) const{
// 	Intersection isec;
// 	for (int i=0; i==5; ++i) {

// 		auto cur_isec = faces_[i].intersect(ray);
// 		if (cur_isec.hit && ((isec.hit && cur_isec.t < isec.t) || !isec.hit)) {
// 			isec = cur_isec;
// 			}
// 		}
// 		return isec;
// 	}
	

// Box::~Box()
// {
// 	std::cout << "~Box destructor called" << std::endl;
// }

#include "Box.hpp"
#include "color.hpp"
#include <glm/gtx/intersect.hpp>

// TODO: anpassen
Box::Box()
  : Shape{}, min_(0,0,0), max_(0,0,0), faces_()
{}


Box::Box(glm::vec3 const& p1, glm::vec3 const& p2, std::string name, std::shared_ptr<Material> const& material)
  : Shape(name, material)
  , min_(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z))
  , max_(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z))
  , faces_()
{
	glm::vec3 ldf (min_.x, min_.y, min_.z);
	glm::vec3 ldb (min_.x, min_.y, max_.z);
	glm::vec3 luf (min_.x, max_.y, min_.z);
	glm::vec3 lub (min_.x, max_.y,max_.z);
	glm::vec3 rdf (max_.x, min_.y, min_.z);
	glm::vec3 rdb (max_.x, min_.y, max_.z);
	glm::vec3 ruf (max_.x, max_.y, min_.z);
	glm::vec3 rub (max_.x, max_.y,max_.z);

	// front face
	Triangle front_t1(rdf, ldf, ruf);
	Triangle front_t2(ruf, ldf, luf);
	Face front(front_t1, front_t2);

	// back face
	Triangle back_t1(ldb, rdb, rub);
	Triangle back_t2(ldb, rub, lub);
	Face back(back_t1, back_t2);

	// up face 
	Triangle up_t1(ruf, luf, rub);
	Triangle up_t2(rub, luf, lub);
	Face up(up_t1, up_t2);

	// down face 
	Triangle down_t1(ldf, rdf, rdb);
	Triangle down_t2(ldf, rdb, ldb);
	Face down(down_t1, down_t2);

	// left face 
	Triangle left_t1(luf, ldf, lub);
	Triangle left_t2(lub, ldf, ldb);
	Face left(left_t1, left_t2);

	// right face 
	Triangle right_t1(rdf, ruf, rub);
	Triangle right_t2(rdf, rub, rdb);
	Face right(right_t1, right_t2);

	faces_[0] = front;
	faces_[1] = back;
	faces_[2] = left;
	faces_[3] = right;
	faces_[4] = up;
	faces_[5] = down;
}

void Box::setMin(glm::vec3 const& min)
{
    min_ = min;
}
void Box::setMinx(double const& minx)
{
    min_.x = minx;
}
void Box::setMiny(double const& miny)
{
    min_.y = miny;
}
void Box::setMinz(double const& minz)
{
    min_.z = minz;
}

void Box::setMax(glm::vec3 const& max)
{
    max_ = max;
}
void Box::setMaxx(double const& maxx)
{
    max_.x = maxx;
}
void Box::setMaxy(double const& maxy)
{
    max_.y = maxy;
}
void Box::setMaxz(double const& maxz)
{
    max_.z = maxz;
}

glm::vec3 Box::getMin() const{
	return min_;
}
glm::vec3 Box::getMax() const{
	return max_;
}

void Box::print(std::ostream& os) const{
	Shape::print(os);
	os << "MinVec: " << min_.x << min_.y << min_.z;
	os << " MaxVec: " << max_.x << max_.y << max_.z;
}

Intersection Box::intersect(Ray const& ray) const{
	Intersection isec;
	for (auto f: faces_) {
		auto cur_isec = f.intersect(ray);
		if (cur_isec.hit && ((isec.hit && cur_isec.t < isec.t) || !isec.hit)) {
			isec = cur_isec;
		}
	}
	return isec;
}
Box::~Box()
{
	std::cout << "~Box destructor called" << std::endl;
}

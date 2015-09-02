#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <glm/glm.hpp>
#include "color.hpp"
#include <math.h>

std::string
make_camera (std::string const& name, double angle, 
	glm::dvec3 const& eye, glm::dvec3 const& dir, glm::dvec3 const& up) 
{
	std::ostringstream result;
	result << "define camera ";
	result << name << " ";
	result << angle << " ";
	result << eye.x << " " << eye.y << " " << eye.z << " ";
	result << dir.x << " " << dir.y << " " << dir.z << " ";
	result << up.x << " " << up.y << " " << up.z << " ";
	return result.str();
}

std::string
make_light (std::string const& name, 
	glm::dvec3 const& p, Color const& ka, Color const& kd) 
{
	std::ostringstream result;
	result << "define light ";
	result << name << " ";
	result << p.x << " " << p.y << " " << p.z << " ";
	result << ka.r << " " << ka.g << " " << ka.b << " ";
	result << kd.r << " " << kd.g << " " << kd.b << " ";
	return result.str();
}

std::string
make_material (std::string const& name, 
	Color const& ka, Color const& kd, Color const& ks, double s) 
{
	std::ostringstream result;
	result << "define material ";
	result << name << " ";
	result << ka.r << " " << ka.g << " " << ka.b << " ";
	result << kd.r << " " << kd.g << " " << kd.b << " ";
	result << ks.r << " " << ks.g << " " << ks.b << " ";
	result << s;
	return result.str();
}

std::string
make_composite (std::string const& name, std::initializer_list<std::string> children) 
{
	std::ostringstream result;
	result << "define shape composite ";
	result << name << " ";
	for (auto c: children) {
		result << c << " ";
	}
	return result.str();
}

std::string
make_sphere (std::string const& name, glm::dvec3 const& origin, double radius, std::string const& matname) 
{
	std::ostringstream result;
	result << "define shape sphere ";
	result << name << " ";
	result << origin.x << " " << origin.y << " " << origin.z << " ";
	result << radius << " ";
	result << matname;
	return result.str();
}

std::string
translate (std::string const& target, glm::dvec3 const& t) 
{
	std::ostringstream result;
	result << "transform ";
	result << target << " ";
	result << "translate ";
	result << t.x << " " << t.y << " " << t.z << " ";
	return result.str();
}

std::string
scale (std::string const& target, glm::dvec3 const& s) 
{
	std::ostringstream result;
	result << "transform ";
	result << target << " ";
	result << "scale ";
	result << s.x << " " << s.y << " " << s.z << " ";
	return result.str();
}

std::string
rotate (std::string const& target, double degree, glm::dvec3 const& axis) 
{
	std::ostringstream result;
	result << "transform ";
	result << target << " ";
	result << "rotate ";
	result << degree << " ";
	result << axis.x << " " << axis.y << " " << axis.z << " ";
	return result.str();
}


std::string
make_box (std::string const& name, glm::dvec3 const& min, glm::dvec3 const& max, std::string const& matname) 
{
	std::ostringstream result;
	result << "define shape box ";
	result << name << " ";
	result << min.x << " " << min.y << " " << min.z << " ";
	result << max.x << " " << max.y << " " << max.z << " ";
	result << matname;
	return result.str();
}

std::string 
make_frame (std::string const& camname, std::string const& ppmfile, glm::ivec2 const& resolution) 
{
	std::ostringstream result;
	result << "render ";
	result << camname << " ";
	result << ppmfile << " ";
	result << resolution.x << " " << resolution.y << " ";
	return result.str();
}

int main (int argc, char* argv[]) {

	const unsigned num_frames = 20;
	const unsigned num_spheres = 10;

	if (argc < 2) {
		std::cout << "you have to give an output path for the SDF file" << std::endl;
		return 1;
	}

	std::ostringstream sdfs;

	// switch on the light
	sdfs << make_light("sun", glm::dvec3(0, 100, 0), Color(0.1, 0.1, 0.1), Color(1, 1, 1)) << std::endl;

	// add some blue material
	sdfs << make_material("blue", Color(0.2, 0.2, 0.2), Color(1, 1, 1), Color(0.2, 0.2, 0.2), 10) << std::endl;

	// create some spheres
	for (int i=0; i<num_spheres; i++) {
		std::ostringstream oss;
		oss << "test";
		oss << i;
		sdfs << make_sphere(oss.str(), glm::dvec3(0,0, 2*i + 5), 1, "blue") << std::endl;
	}

	sdfs << make_camera("eye", 90, glm::dvec3(0, 5, 0), glm::dvec3(0, -1, 1), glm::dvec3(0, 1, 0)) << std::endl;



	// make some frames
	for (int i=0; i<num_frames; i++) {
		std::ostringstream fname;
		fname << "anim/test";
		fname << i;
		fname << ".ppm";

		double t = (double) i / num_frames;

		for (int j=0; j<num_spheres; j++) {
			std::ostringstream sname;
			sname << "test";
			sname << j;

			double s = (double) j / num_spheres;
			double offset = glm::sin(2.0 * M_PI * (t + s));

			sdfs << translate(sname.str(), glm::dvec3(0.0, offset, 0.0)) << std::endl;

		}

		sdfs << make_frame("eye", fname.str(), glm::ivec2(150.0, 150.0)) << std::endl;
	}

	

	std::ofstream ofs(argv[1]);
	ofs << sdfs.str();
	ofs.close();


	return 0;
}
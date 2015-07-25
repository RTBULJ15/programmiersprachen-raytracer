#include "sdf_loader.hpp"

#include <exception>
#include <fstream>
#include <sstream>

SDFLoader::SDFLoader (std::string const& sdfpath) 
 : materials_()
{
	std::ifstream infile;
	infile.open(sdfpath);
	std::string line;

	std::cout << "load " << sdfpath << std::endl;
	while (std::getline(infile, line)) {
		std::istringstream iss(line);

		std::cout << line << std::endl;

		Material mat;

		std::string token_str;
		double token_double;

		// expect material name

		// expect 'define'
		if (!(iss >> token_str) || token_str != "define") {
			throw std::exception();
		}

		// expect 'material'
		if (!(iss >> token_str) || token_str != "material") {
			throw std::exception();
		}

		// expect std::string
		if (!(iss >> token_str)) {
			throw std::exception();
		}
		
		mat.name = token_str;

		// expect ambient color

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ka.r = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ka.g = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ka.b = token_double;



		// expect diffuse color

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.kd.r = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.kd.g = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.kd.b = token_double;

		// expect specular color

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ks.r = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ks.g = token_double;

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.ks.b = token_double;


		// expect specular exponent

		// expect double
		if (!(iss >> token_double)) {
			throw std::exception();
		}
		mat.specular_exp = token_double;


		std::cout << "loaded " << mat << std::endl;

		materials_.push_back(mat);

	}
}

std::vector<Material>
SDFLoader::materials () const
{
	return materials_;
}


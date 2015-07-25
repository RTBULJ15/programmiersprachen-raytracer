#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <vector>
#include <string>
#include "Material.hpp"

class SDFLoader {

public:
	SDFLoader(std::string const& sdfpath);
	std::vector<Material> materials () const;
private:
	std::vector<Material> materials_;
};

#endif
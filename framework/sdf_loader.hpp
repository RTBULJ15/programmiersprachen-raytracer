#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <vector>
#include <string>
#include "scene.hpp"
#include "Material.hpp"
#include "light.hpp"

class SDFLoader {

public:
	SDFLoader(std::string const& sdfpath);
	Scene scene () const;
private:
    Scene scene_;

};

#endif

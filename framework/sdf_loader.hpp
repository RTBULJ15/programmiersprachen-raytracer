#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <vector>
#include <string>
#include "scene.hpp"
#include "Material.hpp"
#include "light.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "renderer.hpp"

class SDFLoader {

public:
	SDFLoader(std::string const& sdfpath);
	//Scene scene () const;
	Scene const& get_scene();
private:
    Scene scene_;

};

#endif

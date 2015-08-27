#define _USE_MATH_DEFINES
#include <cmath>
#include "scene.hpp"
#include <iostream>
#include <vector>

Scene::Scene()
: amb_light_(), lights_(), cam_(), comp_(), materials_(){}


//Scene::Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp)
//{
//}

void Scene::add_mat(std::shared_ptr<Material> const& mat)
{
    materials_.push_back(mat);

}

std::vector<std::shared_ptr<Material>> const& Scene::get_materials()
{
	return materials_;
}

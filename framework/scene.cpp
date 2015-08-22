#define _USE_MATH_DEFINES
#include <cmath>
#include "scene.hpp"
#include <iostream>
#include <vector>

Scene::Scene()
// : amb_light(){0,0,0}, light() {}, cam(){}, comp(){}
{

}


//Scene::Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp)
//{
//}

MaterialContainer& Scene::get_materials()
{
    return materials;
}

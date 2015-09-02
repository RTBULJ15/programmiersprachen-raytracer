#include "scene.hpp"


Scene::Scene()
: bgcolor_(), lights_(), cameras_()
, root_(std::make_shared<Composite>()), materials_(){}

Scene::Scene(Scene const& rhs)
 : bgcolor_(), lights_(), cameras_(), 
 root_(std::dynamic_pointer_cast<Composite>(rhs.root_->clone())), materials_(rhs.materials_)
 {
 	for (auto l : rhs.lights_) {
 		lights_.push_back(l->clone());
 	}
 	for (auto c : rhs.cameras_) {
 		cameras_.push_back(c->clone());
 	}
 }

//Scene::Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp)
//{
//}

void 
Scene::add_camera (std::shared_ptr<Camera> const& camera) 
{
	cameras_.push_back(camera);
}

std::vector<std::shared_ptr<Camera>> const& 
Scene::cameras() const
{
	return cameras_;
}

void Scene::add_material(std::shared_ptr<Material> const& mat)
{
    materials_.push_back(mat);

}

std::vector<std::shared_ptr<Material>> const& Scene::get_materials()
{
	return materials_;
}

void Scene::add_light(std::shared_ptr<Light> const& light){
	lights_.push_back(light);
}

std::vector<std::shared_ptr<Light>> const& Scene::get_lights(){
	return lights_;
}

std::shared_ptr<Composite> const&
Scene::root () const
{
	return root_;
}

void
Scene::add_shape (std::shared_ptr<Shape> const& shape)
{
	root_->add_child(shape);
}

std::shared_ptr<Scene> 
Scene::clone () const 
{
	return std::make_shared<Scene>(*this);
}

Color 
Scene::bgcolor () const 
{
	return bgcolor_;
}
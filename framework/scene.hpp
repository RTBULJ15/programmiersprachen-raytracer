# ifndef BUW_SCENE_HPP
# define BUW_SCENE_HPP
#include <memory>
#include <vector>
#include <glm/vec3.hpp>
#include "color.hpp"
#include "light.hpp"
#include "composite.hpp"
#include "camera.hpp"
#include "Material.hpp"


// typedef std::vector<std::shared_ptr<Material>> MaterialContainer;

class Scene
{
 public:
    Scene();
    //Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp);
    Camera const& get_camera();
    /*get_amb_light();
    get_lights();
    get_cam();
    get_comp(); */
    	/* : lights{}
	, composite{} */
    void add_mat(std::shared_ptr<Material> const& mat);
    std::vector<std::shared_ptr<Material>> const& get_materials();

    void add_light(std::shared_ptr<Light> const& light);
    std::vector<std::shared_ptr<Light>> const& get_lights();

 private:
    Color amb_light_;
    std::vector<std::shared_ptr<Light>> lights_;
    Camera cam_;
    Composite comp_;
    std::vector<std::shared_ptr<Material>> materials_;

	/*
	std::vector<Light> lights;
	Composite composite;
	*/
};

#endif

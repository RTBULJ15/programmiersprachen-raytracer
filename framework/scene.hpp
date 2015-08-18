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


typedef std::vector<std::shared_ptr<Material>> MaterialContainer;

class Scene
{
 public:
    Scene(){};
    //Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp);
    Camera get_camera(){};
    /*get_amb_light();
    get_lights();
    get_cam();
    get_comp(); */
    	/* : lights{}
	, composite{} */
    MaterialContainer  get_materials(){};
 private:
    Color amb_light;
    std::vector<Light> lights;
    Camera cam;
    Composite comp;
    MaterialContainer materials;

	/*
	std::vector<Light> lights;
	Composite composite;
	*/
};

#endif

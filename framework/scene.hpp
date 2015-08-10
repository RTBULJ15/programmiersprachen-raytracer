# ifndef BUW_SCENE_HPP
# define BUW_SCENE_HPP
#include <glm/vec3.hpp>
#include "color.hpp"
#include "light.hpp"
#include "composite.hpp"
#include "camera.hpp"

struct Scene
{
 public:
    Scene();
	Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp);
	Camera get_camera();
    /*get_amb_light();
    get_lights();
    get_cam();
    get_comp(); */
    	/* : lights{}
	, composite{} */
 private:
    Color amb_light;
    std::vector<Light> lights;
    Camera cam;
    Composite comp;

	/*
	std::vector<Light> lights;
	Composite composite;
	*/
};

#endif

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
    Scene(Scene const& rhs);
    //Scene(Color amb_light, std::vector<Light> lights, Camera cam , Composite comp);

    void add_camera (std::shared_ptr<Camera> const& camera);
    std::vector<std::shared_ptr<Camera>> const& cameras() const;
    /*get_amb_light();
    get_lights();
    get_cam();
    get_comp(); */
    	/* : lights{}
	, composite{} */
    void add_material(std::shared_ptr<Material> const& mat);
    std::vector<std::shared_ptr<Material>> const& get_materials();

    void add_light(std::shared_ptr<Light> const& light);
    std::vector<std::shared_ptr<Light>> const& get_lights();


    void add_shape (std::shared_ptr<Shape> const& shape);
    std::shared_ptr<Composite> const& root () const;

    std::shared_ptr<Scene> clone () const;

    Color bgcolor () const;

    friend std::ostream& operator << (std::ostream& os, Scene const& scene) {
        os << "{Scene ";
        os << scene.bgcolor_ << " ";
        os << *(scene.root_) << " ";
        for (auto l: scene.lights_) {
            os << *l << " ";
        }
        for (auto c: scene.cameras_) {
            os << *c << " ";
        }
        for (auto m: scene.materials_) {
            os << *m << " ";
        }
        os << "}";
        return os;
    }

 private:
    Color bgcolor_;
    std::vector<std::shared_ptr<Light>> lights_;
    std::vector<std::shared_ptr<Camera>> cameras_;
    std::shared_ptr<Composite> root_;
    std::vector<std::shared_ptr<Material>> materials_;

	/*
	std::vector<Light> lights;
	Composite composite;
	*/
};

#endif

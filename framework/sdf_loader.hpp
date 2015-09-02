#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include <vector>
#include <string>
#include <memory>
#include <map>

#include "scene.hpp"
#include "Material.hpp"
#include "light.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "rendertask.hpp"
#include "renderer.hpp"

class SDFLoader {

	template <typename T>
	T fetch_primitive (std::istringstream& iss) const;

	glm::ivec2 fetch_ivec2(std::istringstream& iss) const;
	glm::dvec3 fetch_dvec3 (std::istringstream& iss) const;

	Color fetch_color(std::istringstream& iss) const;

	const std::shared_ptr<Material> lookup_material (std::string const& material_name) const;
	const std::shared_ptr<Camera> lookup_camera (std::string const& camera_name) const;
	const std::shared_ptr<Shape> lookup_shape (std::string const& shape_name) const;

	std::shared_ptr<Shape> fetch_composite (std::istringstream& iss);
	std::shared_ptr<Shape> fetch_sphere (std::istringstream& iss) const;
	std::shared_ptr<Shape> fetch_box (std::istringstream& iss) const;
	std::shared_ptr<Shape> fetch_shape (std::istringstream& iss);
	std::shared_ptr<Material> fetch_material (std::istringstream& iss) const;
	std::shared_ptr<Light> fetch_light (std::istringstream& iss) const;
	std::shared_ptr<Camera> fetch_camera (std::istringstream& iss) const;

	void parseTranslation (std::shared_ptr<Shape>  const& shape, std::istringstream& iss);
	void parseRotation (std::shared_ptr<Shape>  const& shape, std::istringstream& iss);
	void parseScale (std::shared_ptr<Shape>  const& shape, std::istringstream& iss);

	RenderTask fetch_render_task (std::istringstream& iss) const;

	void parseTransformation (std::istringstream& iss);
	void parseDefinition (std::istringstream& iss);
	void parseLine (std::string const& line);

public:
	SDFLoader(std::string const& sdfpath);
	//Scene scene () const;
	std::vector<RenderTask> const& tasks() const;
private:
    std::vector<RenderTask> tasks_;

    std::map<std::string, std::shared_ptr<Camera>> cameras_;
    std::map<std::string, std::shared_ptr<Material>> materials_;
    std::map<std::string, std::shared_ptr<Shape>> shapes_;
    std::map<std::string, std::shared_ptr<Light>> lights_;

};

#endif

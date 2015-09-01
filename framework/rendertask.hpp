#ifndef BUW_RENDERTASK_HPP
#define BUW_RENDERTASK_HPP

#include <string>
#include <memory>
#include <glm/glm.hpp>

#include "scene.hpp"
#include "camera.hpp"

struct RenderTask
{
	RenderTask (std::shared_ptr<Camera> const& cam, std::shared_ptr<Scene> const& scn, std::string const& ipath, glm::ivec2 const& res)
	 : camera(cam)
	 , scene(scn)
	 , imagepath(ipath)
	 , resolution(res)
	{}

	std::shared_ptr<Camera> camera;
	std::shared_ptr<Scene> scene;
	std::string imagepath;
	glm::ivec2 resolution;
};

#endif // BUW_RENDERTASK_HPP
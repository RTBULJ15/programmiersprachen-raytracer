#include "raycaster.hpp"

Raycaster::Raycaster()
:scene_{}
{}

Raycaster::Raycaster(std::shared_ptr<Scene> const& scene)
:scene_(scene)
{}

Intersection 
Raycaster::trace (Ray const& ray)
{
	return scene_->root()->intersect(ray);
}

Color 
Raycaster::shade(Ray const& ray, Intersection const& isec)
{
	if (isec.hit && ray.depth > 0) {
		auto p = ray.origin + isec.t * ray.direction;
		Color result;
		for (auto l: scene_->get_lights()) {
			auto ldir = glm::normalize(l->position() - p);
			result += l->ambient();
			Ray sh_ray(p + RAY_EPSILON * isec.normal, ldir, ray.depth - 1);
			auto sh_isec = trace(sh_ray);
			if (!sh_isec.hit) {
				auto eye = -ray.direction;
				auto reflect = glm::reflect(ldir, isec.normal);
				auto int_diff = glm::max(0.0, glm::min(1.0, glm::dot(isec.normal, ldir)));
				auto int_spec = glm::pow(
					glm::max(0.0, glm::min(1.0, glm::dot(-eye, reflect))),
					isec.material->specular_exp
				);
				result += l->diffuse() * isec.material->kd * int_diff;
				result += l->diffuse() * isec.material->ks * int_spec;
			}
		}
		return result;
	} else {
		return scene_->bgcolor();
	}
}

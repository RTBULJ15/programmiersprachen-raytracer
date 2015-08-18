#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.hpp"
#include "Box.hpp"
#include <glm/gtx/intersect.hpp>
#include "sdf_loader.hpp"

template <typename T>
void print_vector (T v) {
	std::cout << v.x << " " << v.y << " " << v.z;
}

/*TEST_CASE("Sphere", "[Sphere]"){

	Material black;

	Sphere kugel{glm::vec3{0.0f,0.0f,0.0f},1.0f, "default", black};


	REQUIRE(kugel.volume()==Approx(4.189).epsilon(0.17));
	REQUIRE(kugel.area()==Approx(12.566).epsilon(0.17));
}

TEST_CASE("Box", "[Box]"){

	Material black;

	Box box{glm::vec3 {0.0,0.0,0.0}, glm::vec3 {1.0,1.0,1.0}, "default", black};

	REQUIRE(box.area()==Approx(6.0f));
	REQUIRE(box.volume()==Approx(1.0f));
}

TEST_CASE("intersectRaySphere", "[intersect]")
{
	// Ray
	glm::vec3 ray_origin(0.0,0.0,0.0);
	// ray direction has to be normalized!
	// you can use:
	// v=glm::normalize(some_vector)
	glm::vec3 ray_direction(0.0,0.0,1.0);

	//Sphere
	glm::vec3 sphere_center(0.0,0.0,5.0);
	float sphere_radius(1.0);

	float distance(0.0);
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center, sphere_radius,
		distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("Sphere intersect", "[intersect]")
{

	Material* mat = new Material();

	Sphere s0{{0.0, 0.0, 0.0}, 1.0, "s0", mat};

	Ray r{{0.0, 0.0, -2.0}, {0.0, 0.0, 1.0}};

	auto isec = s0.intersect(r);

	//print_vector (isec.position);
	//print_vector (isec.normal);

	REQUIRE (glm::distance(glm::vec3(0.0, 0.0, -1.0), isec.position) == Approx(0.0));
	REQUIRE (glm::distance(glm::vec3(0.0, 0.0, -1.0), isec.normal) == Approx(0.0));
	REQUIRE (isec.hit);

}

TEST_CASE("Shape", "[destructor")
{
	Color red(255,0,0);

	Material* mat = new Material();
	mat->kd = red;

	glm::vec3 position(0,0,0);
	Sphere* s1 = new Sphere(position, 1.2f, "sphere0", mat);
	Shape* s2 = new Sphere(position, 1.2f, "sphere1", mat);

	s1->print(std::cout);
	s2->print(std::cout);

	delete s1;
	delete s2;
}

TEST_CASE("Box_inter", "[intersect]")
{
	Material* mat = new Material();
	Box box1{{1.0,1.0,1.0},{1.2,2.0,2.0}, "karl", mat};
	Ray charles{{0.0,0.0,0.0},{3.0,3.0,3.0}};
	REQUIRE (box1.intersect(charles).hit);
} */

TEST_CASE("sdf loader", "[load]")
{
	SDFLoader loader("/opt/raytracer/2/programmiersprachen-raytracer/tests/scene.sdf");

	/*for (auto mat: loader.materials()) {
		std::cout << mat;
	}*/
}



int main(int argc, char *argv[])
{
  /*Material* mat = new Material();
  Sphere kugel{glm::vec3{0.0f,0.0f,0.0f},1.0f, "Koogle", mat};
  Box box{glm::vec3{0.0f,0.0f,0.0f},glm::vec3{0.0f,0.0f,0.0f}, "Box_1", mat};
  std::cout << kugel << std::endl << box << std::endl;

	SDFLoader loader("/opt/raytracer/2/programmiersprachen-raytracer/source/tests/scene.sdf");
    /*SDFLoader loader("materials.sdf");
	for (auto mat: loader.materials()) {
		std::cout << mat
	 */

  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.hpp"
#include "Box.hpp"
#include <glm/gtx/intersect.hpp>
#include "sdf_loader.hpp"
#include "intersection.hpp"
#include "light.hpp"

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
// TEST_CASE("Sphere_normale", "[load]")
// {
// 	std::shared_ptr<Material> black = std::make_shared<Material>();

// 	Sphere kugel{glm::vec3{0.0f,0.0f,10.0f},2.0f, "default", black};

// 	Box box{glm::vec3{0.0,0.0,3.0}, glm::vec3{3.0,0.0,4.0}, "testbox", black};

// 	Ray strahl{{0.0,0.0,0.0},{.0,0.11,1.0}};

// 	Light sonne("bla" ,{25.0,15.0,1.9}, {0.0,10.1,10.0}, {10.0,10.1,10.0});

// 	Intersection isec = box.intersect(strahl);

// 	glm::vec3 sunPos = sonne.getPos();
    
 //    glm::vec3 Lichtstrahl = sunPos - isec.position ;

 //      glm::normalize(Lichtstrahl);
 //      float phong = std::cos(glm::dot( isec.normal, Lichtstrahl));

	// std::cout<< phong <<" " << isec.normal[0] <<" "<< isec.normal[1] <<" "<< isec.normal[2] <<" " << std::endl;


// }
TEST_CASE("sdf loader", "[load]")
{
	SDFLoader loader("/home/jo/raytracer2/programmiersprachen-raytracer/tests/scene.sdf");
	Scene test = loader.get_scene();
	auto vecmat = test.get_materials();

	std::cout << *vecmat[0] << std::endl;
	// for (auto mat: scene.get_materials_()) {
	// 	std::cout << mat;
	// };
}



int main(int argc, char *argv[])
{
  // Material* mat = new Material();
  // Sphere kugel{glm::vec3{0.0f,0.0f,0.0f},1.0f, "Koogle", mat};
  // Box box{glm::vec3{0.0f,0.0f,0.0f},glm::vec3{0.0f,0.0f,0.0f}, "Box_1", mat};
  // std::cout << kugel << std::endl << box << std::endl;

	// SDFLoader loader("/opt/raytracer/2/programmiersprachen-raytracer/source/tests/scene.sdf");
 //    SDFLoader loader("materials.sdf");
	// for (auto mat: loader.materials()) {
	// 	std::cout << mat
	 

  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.hpp"
#include "Box.hpp"

TEST_CASE("Sphere", "[Sphere]"){
	
	Sphere kugel{glm::vec3{0.0f,0.0f,0.0f},1.0f, "default", {0,0,0}};
	
	
	REQUIRE(kugel.volume()==Approx(4.189).epsilon(0.17));
	REQUIRE(kugel.area()==Approx(12.566).epsilon(0.17));
}

TEST_CASE("Box", "[Box]"){

	Box box{glm::vec3 {0.0,0.0,0.0}, glm::vec3 {1.0,1.0,1.0}, "default", {0,0,0}};

	REQUIRE(box.area()==Approx(6.0f));
	REQUIRE(box.volume()==Approx(1.0f));
}

int main(int argc, char *argv[])
{
  Sphere kugel{glm::vec3{0.0f,0.0f,0.0f},1.0f, "Koogle", {1.0,0.2,0.4}};
  Box box{glm::vec3{0.0f,0.0f,0.0f},glm::vec3{0.0f,0.0f,0.0f}, "Box_1", {1.0,0.4,0.5}};
  std::cout << kugel << std::endl << box << std::endl;

  return Catch::Session().run(argc, argv);
}

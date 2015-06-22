#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.hpp"
#include "Box.hpp"

TEST_CASE("Sphere", "[Sphere]"){
	Sphere kugel{glm::vec3{1.0f,1.0f,1.0f},1.0f};

REQUIRE(kugel.volume()==Approx(4.189));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

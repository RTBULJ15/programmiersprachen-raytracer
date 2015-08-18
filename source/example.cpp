
#include <omp.h>

#include "Shape.hpp"
#include "Box.hpp"
#include "Material.hpp"
#include "fensterchen.hpp"
#include "Ray.hpp"
#include "intersection.hpp"
#include "Sphere.hpp"

int main(int argc, char* argv[])
{
 Material black;
 float depth = 100.0;
    glm::vec3 offset(0, 0, 0);
    Box test_box(glm::vec3{-1.0,-1.0,5.0} + offset, glm::vec3{1.0,1.0,6.0} + offset,"testbox", black);
    Sphere test_kreis(glm::vec3{0.0,0.0,5.0}, 1.0,"testkreis", black);
    Triangle test_triangle({1,0,5},{-1,0,5},{0,1,5});

  int win_size_x=400;
  int win_size_y=400;
  float xpos_pro=1/float(win_size_x);
  float ypos_pro=1/float(win_size_y);
  Window win(glm::ivec2(win_size_x,win_size_y));



glm::vec3 eye{0, 0, 0};
float focal_length = 2.0;

float t = 0;

win.update();



while (!win.shouldClose()) {
  #pragma omp parallel for collapse(2) 
  for(int i=0; i<win_size_x; i++){
    for(int u=0; u<win_size_y; u++){

      float x = float(i) / win_size_x;
      float y = float(u) / win_size_y;

      auto ray_dir = glm::normalize(glm::vec3{2*x-1, 2*y-1, focal_length});
      Ray charles(eye, ray_dir);
      auto isec = test_triangle.intersect(charles);
      
    
      if (isec.hit){
        win.drawPoint(x,y,glm::abs(std::cos(isec.normal.x)) * 255, 
                          glm::abs(std::cos(isec.normal.y)) * 255, 
                          glm::abs(std::cos(isec.normal.z)) * 255);
         }
      // else{
      //   win.drawPoint(x,y, 33.0,33.0,33.0);
      // }
            
    }
    
  }
  eye.y = 2.0 * std::sin(t);
  eye.x = 2.0 * std::cos(t);
  t += 1e-2;
  win.update();
}

  return 0;
}

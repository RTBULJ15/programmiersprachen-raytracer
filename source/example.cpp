
#include <omp.h>

#include "Shape.hpp"
#include "Box.hpp"
#include "Material.hpp"
#include "fensterchen.hpp"
#include "Ray.hpp"
#include "intersection.hpp"
#include "Sphere.hpp"
#include "light.hpp"
#include "composite.hpp"

int main(int argc, char* argv[])
{
    std::shared_ptr<Material> black = std::make_shared<Material>();
    float depth = 100.0;
    glm::vec3 offset(0, 0, 0);
     Box test_box(glm::vec3{-1.5,-1.0,5.0} + offset, glm::vec3{0.9,1.0,6.0} + offset,"testbox", black);
    Sphere test_kreis(glm::vec3{0.0,0.0,4.0}, 1.0,"testkreis", black);
  // Triangle test_triangle({1,0,5},{-1,0,5},{0,1,5});
    Light sonne("bla" ,{4.0,0.0,3.0}, {0.0,10.1,10.0}, {10.0,10.1,10.0});
    Composite comp;
    
auto r = std::make_shared<Box>(glm::vec3{-4.5,-1.0,5.0} + offset, glm::vec3{-2.0,1.0,6.0} + offset,"testbox", black);
  std::shared_ptr<Shape> s = r;
  comp.add_child(s);
  auto bla = std::make_shared<Sphere>(glm::vec3{0.0,0.0,4.0}, 1.0,"testkreis", black);
  std::shared_ptr<Shape> blabla = bla;
  comp.add_child(blabla);
  int win_size_x=400;
  int win_size_y=400;
  float xpos_pro=1/float(win_size_x);
  float ypos_pro=1/float(win_size_y);
  Window win(glm::ivec2(win_size_x,win_size_y));



	glm::vec3 eye{0, 0, 0};
	float focal_length = 1.0;

	// float t = 0;

	win.update();



while (!win.shouldClose()) {
  #pragma omp parallel for collapse(2) 
  for(int i=0; i<win_size_x; i++){
    for(int u=0; u<win_size_y; u++){

      float x = float(i) / win_size_x;
      float y = float(u) / win_size_y;

      auto ray_dir = glm::normalize(glm::vec3{2*x-1, 2*y-1, focal_length});
      Ray charles(eye, ray_dir);
      Intersection isec = comp.intersect(charles);

     //  std::cout<<isec.t<<std::endl;
     // std::vector<std::shared_ptr<Shape>> foo = comp.get_child_vec();
     // glm::vec3 foofoo = *foo[0].getcenter();
     // std::cout<<foo.size()<<std::endl;
      
      
     // glm::vec3 kreisPos = test_kreis.getcenter();
    // std::cout<<isec.position[0]<<" "<<isec.position[1]<<" "<<isec.position[2]<<" "<<std::endl;
    // std::cout<<ray_dir[0]<<" "<<ray_dir[1]<<" "<<ray_dir[2]<<" "<<std::endl;
      if (isec.hit){
        glm::vec3 sunPos = sonne.getPos();
      glm::vec3 Lichtstrahl =  sunPos - isec.position ;

      // glm::normalize(Lichtstrahl);
      // float phong = glm::abs(std::cos(glm::dot(isec.normal, Lichtstrahl)));
      // if (phong > 1 || phong < 0 ){phong = 0;};
      float phong = glm::abs(glm::dot(isec.normal, Lichtstrahl));
      
        // std::cout<<phong<<std::endl;

       float schatten_abfr = glm::length(Lichtstrahl);
      Ray schatten_ray(isec.position, glm::normalize(Lichtstrahl));
      Intersection schatten_isec = comp.intersect(schatten_ray);
      if(isec.hit && !(schatten_isec.t==-1)){phong = 0;}
      std::cout<<schatten_abfr<<std::endl;  
        // float r = 
        // float g = 
        // float b = 
      // if (phong<0){phong=0;}
        win.drawPoint(x,y, 55*phong, 
                           55*phong, 
                           55);
         
         // win.drawPoint(x,y,glm::abs(std::cos(isec.normal.x)) * 255, 
         //                  glm::abs(std::cos(isec.normal.y)) * 255 , 
         //                  glm::abs(std::cos(isec.normal.z)) * 255) ;
         }
      // else{
      //   win.drawPoint(x,y, 33.0,33.0,33.0);
      // }
            
    }
    
  }
  // eye.y = 2.0 * std::sin(t);
  // eye.x = 2.0 * std::cos(t);
  // // float t = 1.0;
  // t += 1e-2;
 win.update();
  
}

  return 0;
}

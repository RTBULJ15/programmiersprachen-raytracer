
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
    std::shared_ptr<Material> black = std::make_shared<Material>
    ("mat1",Color(256.0,256.0,56.0), Color(56.0,56.0,56.0), Color(256.0,256.0,256.0), 1.0);
    
    double depth = 100.0;
    glm::dvec3 offset(0, 0, 0);
     // Box test_box(glm::dvec3{-0.5,-0.2,5.0} + offset, glm::dvec3{0.09,0.5,6.0} + offset,"testbox", black);
    Sphere test_kreis(glm::dvec3{0.0,0.0,4.0}, 1.0,"testkreis", black);
  // Triangle test_triangle({1,0,5},{-1,0,5},{0,1,5});
    Light sonne("bla" ,{20.0,10.0,5.0}, {0.0,10.1,10.0}, {10.0,10.1,10.0});
    Light sonne2("bla2" ,{0.0,2.0,0.0}, {0.0,10.1,10.0}, {10.0,10.1,10.0});
    Composite comp;
    double t = 0.01;
auto r = std::make_shared<Box>(glm::dvec3{-3.0,-0.5,3} + offset, glm::dvec3{-0.5,-1.5,9.0} + offset,"testbox", black);
  //auto r = std::make_shared<Sphere>(glm::dvec3{1.0,0.0,4.0}, 1.0,"testkreis", black);
  std::shared_ptr<Shape> s = r;
  comp.add_child(s);
  auto bla = std::make_shared<Sphere>(glm::dvec3{1.0,0.0,5.0}, 1.0,"testkreis", black);
std::shared_ptr<Shape> blabla = bla;
  comp.add_child(blabla);
  int win_size_x=600;
  int win_size_y=600;
  double xpos_pro=1/double(win_size_x);
  double ypos_pro=1/double(win_size_y);
  Window win(glm::ivec2(win_size_x,win_size_y));



	glm::dvec3 eye{0, 0, 0};
	double focal_length = 1.0;

	// double t = 0;

	win.update();



while (!win.shouldClose()) {
  #pragma omp parallel for collapse(2) 
  for(int i=0; i<win_size_x; i++){
    for(int u=0; u<win_size_y; u++){

      double x = double(i) / win_size_x;
      double y = double(u) / win_size_y;

      auto ray_dir = glm::normalize(glm::dvec3{2*x-1, 2*y-1, focal_length});
      Ray charles(eye, ray_dir);
      Intersection isec = comp.intersect(charles);

     //  std::cout<<isec.t<<std::endl;
     // std::vector<std::shared_ptr<Shape>> foo = comp.get_child_vec();
     // glm::dvec3 foofoo = *foo[0].getcenter();
     // std::cout<<foo.size()<<std::endl;
      
      
     // glm::dvec3 kreisPos = test_kreis.getcenter();
    // std::cout<<isec.position[0]<<" "<<isec.position[1]<<" "<<isec.position[2]<<" "<<std::endl;
    // std::cout<<ray_dir[0]<<" "<<ray_dir[1]<<" "<<ray_dir[2]<<" "<<std::endl;
      if (isec.hit){
        auto p = charles.origin + (double) isec.t * charles.direction;
        glm::dvec3 sunPos = sonne.getPos();
      glm::dvec3 Lichtstrahl =  glm::normalize(sunPos - p);

      //  glm::dvec3 sunPos2 = sonne2.getPos();
      // glm::dvec3 Lichtstrahl2 =  sunPos2 - isec.position ;

      // glm::normalize(Lichtstrahl);
      // double phong = glm::abs(std::cos(glm::dot(isec.normal, Lichtstrahl)));
      // if (phong > 1 || phong < 0 ){phong = 0;};
      double phong = glm::max(0.0, glm::min(1.0, glm::dot(isec.normal, Lichtstrahl)));
      // double phong2 = glm::abs(glm::dot(isec.normal, Lichtstrahl2));
        // std::cout<<phong<<std::endl;

       double schatten_abfr = glm::abs(glm::length(Lichtstrahl));

       

      Ray schatten_ray(p, glm::normalize(Lichtstrahl));
      Intersection schatten_isec = comp.intersect(schatten_ray);


      phong += 0.5;
      if (schatten_isec.hit) {
        phong = 0;
      }


      //if(schatten_isec.hit && schatten_abfr > schatten_isec.t + 0.01){phong = 0;}
      // std::cout<<isec.t<<std::endl;  

      // if (phong<0){phong=0;}
        
        // win.drawPoint(x,y, black->kd.r*phong, 
        //                    black->kd.g*phong, 
        //                    black->kd.b);
         
         win.drawPoint(x,y, 255*isec.t / 7, 
                           255*isec.t / 7, 
                           255*isec.t / 7);
            /*win.drawPoint(x,y, black->kd.r*phong, 
                           black->kd.g*phong, 
                           black->kd.b*phong);*/
    /*     win.drawPoint(x,y,isec.normal.x * 255, 
                          isec.normal.y * 255 , 
                          isec.normal.z * 255);*/
         
      // else{
      //   win.drawPoint(x,y, 33.0,33.0,33.0);
     }
            
    }
    
  }
  // double t = 1.0;
  // eye.y = 2.0 * std::sin(t);
  // eye.x = 2.0 * std::cos(t);
  
  // t += 1e-2;
  // sonne.setPosition_x(sonne.getPos_x()+t);
 win.update();
  
}

  return 0;
}

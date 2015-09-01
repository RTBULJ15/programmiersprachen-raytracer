// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
// 2.Edit     : Leah-M. Walterscheid & Jonathan-D. Wedler
// Renderer
// -----------------------------------------------------------------------------

#include <omp.h>
#include "renderer.hpp"
#include "raycaster.hpp"

Renderer::Renderer(RenderTask const& task)
  : img_(task.resolution)
  , task_(task)
{}

Image const&
Renderer::image() const 
{
  return img_;
}

Image 
Renderer::render()
{
  Raycaster rc(task_.scene);

  #pragma omp parallel for collapse(2) 
  for (int x=0; x<task_.resolution.x; ++x) {
    for (int y=0; y<task_.resolution.y; ++y) {
      auto rx = (double) x / task_.resolution.x;
      auto ry = (double) y / task_.resolution.y;
      auto origin = glm::dvec3(0, 0, 0);
      auto direction = glm::normalize(glm::dvec3(2*rx-1, 2*ry-1, task_.camera->focallength()));
      Ray r(origin, direction);
      auto cl = rc.shade(r, rc.trace(r));
      img_.setPixel(Pixel(x,y,cl));
    }
  }
  return img_;

  /*const std::size_t checkersize = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      if ( ((x/checkersize)%2) != ((y/checkersize)%2)) {
        p.color = Color(0.0, 1.0, float(x)/height_);
      } else {
        p.color = Color(1.0, 0.0, float(y)/width_);
      }

      write(p);
    }
  }
  ppm_.save(filename_);*/
}

/*void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}*/



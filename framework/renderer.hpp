// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
// 2.Edit     : Leah-M. Walterscheid & Jonathan-D. Wedler
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include <string>
#include <glm/glm.hpp>
#include <iostream>
#include "intersection.hpp"
#include "Ray.hpp"
#include "scene.hpp"

class Renderer
{
public:

  Renderer(unsigned w, unsigned h, std::string const& file);

  void render();
  void write(Pixel const& p);


  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }

private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
};

#endif // #ifndef BUW_RENDERER_HPP

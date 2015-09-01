#include <thread>

#include "Shape.hpp"
#include "Box.hpp"
#include "Material.hpp"
#include "fensterchen.hpp"
#include "Ray.hpp"
#include "intersection.hpp"
#include "Sphere.hpp"
#include "light.hpp"
#include "composite.hpp"
#include "sdf_loader.hpp"
#include "imagewriter.hpp"

int main(int argc, char* argv[])
{
  bool close_window = false;

  if (argc < 2) {
    std::cout << "usage: example <sdf path> <auto-close>" << std::endl;
    return 1;
  }

  std::string sdfpath(argv[1]);

  if (argc > 2) {
    close_window = true;
  }


  SDFLoader sdfloader(sdfpath);
  auto scene = sdfloader.scene();
  auto tasks = sdfloader.tasks();

  std::cout << "finished loading sdf" << std::endl;

  for (auto task: tasks) {

    bool is_task_done = false;

    Renderer renderer(task);

    std::cout << "starting render thread" << std::endl;
    std::thread thr([&renderer, &is_task_done]() { 
      renderer.render(); 
      is_task_done = true;
    });

    Window win(task.resolution);

    while (!win.shouldClose()) {
      if (win.isKeyPressed(GLFW_KEY_ESCAPE) || (close_window && is_task_done)) {
        win.stop();
      }

      glDrawPixels( task.resolution.x, task.resolution.y, GL_RGB, GL_FLOAT
        , renderer.image().colorbuffer().data());

      win.update();
    }
    

    thr.join();

    ImageWriter imgwriter(renderer.image());
    imgwriter.write(task.imagepath);
  }

  // std::cout<<cam.focallength()<<std::endl;
  return 0;
}
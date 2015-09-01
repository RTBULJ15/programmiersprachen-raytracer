#include "sdf_loader.hpp"

#include <exception>
#include <fstream>
#include <sstream>

#include <memory>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "scene.hpp"
#include "Material.hpp"
#include "light.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "renderer.hpp"


template <typename T>
T
SDFLoader::fetch_primitive (std::istringstream& iss) const
{
  T result;
  if (!(iss >> result)) {
    throw std::runtime_error(std::string("wrong primitive type"));
  }
  return result;
}

glm::ivec2 
SDFLoader::fetch_ivec2(std::istringstream& iss) const
{
  auto x = fetch_primitive<int>(iss);
  auto y = fetch_primitive<int>(iss);
  return glm::ivec2(x, y);
}

glm::dvec3 
SDFLoader::fetch_dvec3 (std::istringstream& iss) const
{
  auto x = fetch_primitive<double>(iss);
  auto y = fetch_primitive<double>(iss);
  auto z = fetch_primitive<double>(iss);
  return glm::dvec3(x, y, z);
}

Color
SDFLoader::fetch_color (std::istringstream& iss) const
{
  auto r = fetch_primitive<double>(iss);
  auto g = fetch_primitive<double>(iss);
  auto b = fetch_primitive<double>(iss);
  return Color(r, g, b);
}

const std::shared_ptr<Shape>
SDFLoader::lookup_shape (std::string const& shape_name) const
{
  auto it = shapes_.find(shape_name);
  if (it == shapes_.end()) {
    throw std::runtime_error(std::string("no shape with name: " + shape_name));
  }
  return it->second;
}

const std::shared_ptr<Material>
SDFLoader::lookup_material (std::string const& material_name) const
{
  auto it = materials_.find(material_name);
  if (it == materials_.end()) {
    throw std::runtime_error(std::string("no material with name: " + material_name));
  }
  return it->second;
}

const std::shared_ptr<Camera>
SDFLoader::lookup_camera (std::string const& camera_name) const
{
  auto it = cameras_.find(camera_name);
  if (it == cameras_.end()) {
    throw std::runtime_error(std::string("no camera with name: " + camera_name));
  }
  return it->second;
}

std::shared_ptr<Shape>
SDFLoader::fetch_sphere (std::istringstream& iss) const
{
  auto name = fetch_primitive<std::string>(iss);
  auto origin = fetch_dvec3(iss);
  auto radius = fetch_primitive<double>(iss);
  auto material = lookup_material(fetch_primitive<std::string>(iss));
  return std::make_shared<Sphere>(name, origin, radius, material);
}

std::shared_ptr<Shape>
SDFLoader::fetch_composite (std::istringstream& iss)
{
  auto name = fetch_primitive<std::string>(iss);
  auto composite = std::make_shared<Composite>();

  composite->name(name);

  while (!iss.eof()) {
    auto childname = fetch_primitive<std::string>(iss);
    auto child = lookup_shape(childname);
    composite->add_child(child);
    shapes_.erase(child->name());
  }

  return composite;
}

std::shared_ptr<Shape>
SDFLoader::fetch_box (std::istringstream& iss) const
{
  auto name = fetch_primitive<std::string>(iss);
  auto min = fetch_dvec3(iss);
  auto max = fetch_dvec3(iss);
  auto material = lookup_material(fetch_primitive<std::string>(iss));
  return std::make_shared<Box>(name, min, max, material);
}

std::shared_ptr<Camera>
SDFLoader::fetch_camera (std::istringstream& iss) const
{
  auto name = fetch_primitive<std::string>(iss);
  auto angle = fetch_primitive<double>(iss);
  return std::make_shared<Camera>(name, angle);
}

std::shared_ptr<Shape>
SDFLoader::fetch_shape (std::istringstream& iss)
{
  auto shapetype = fetch_primitive<std::string>(iss);
  if (shapetype == "sphere") {
    return fetch_sphere(iss);
  } else if (shapetype == "box") {
    return fetch_box(iss);
  } else if (shapetype == "composite") {
    return fetch_composite(iss);
  } else {
    throw std::runtime_error(std::string("unkown shape: " + shapetype));
  }
}



std::shared_ptr<Material>
SDFLoader::fetch_material (std::istringstream& iss) const
{
  auto name = fetch_primitive<std::string>(iss);
  auto ambient = fetch_color(iss);
  auto diffuse = fetch_color(iss);
  auto specular = fetch_color(iss);
  auto specexponent = fetch_primitive<double>(iss);
  return std::make_shared<Material>(name, ambient, diffuse, specular, specexponent);
}

std::shared_ptr<Light>
SDFLoader::fetch_light (std::istringstream& iss) const
{
  auto name = fetch_primitive<std::string>(iss);
  auto position = fetch_dvec3(iss);
  auto ambient = fetch_color(iss);
  auto diffuse = fetch_color(iss);
  return std::make_shared<Light>(name, position, ambient, diffuse);
}

RenderTask 
SDFLoader::fetch_render_task (std::istringstream& iss) const 
{
  auto camera = lookup_camera(fetch_primitive<std::string>(iss));
  auto filename = fetch_primitive<std::string>(iss);
  auto resolution = fetch_ivec2(iss);
  return RenderTask(camera, scene_, filename, resolution);
}

void 
SDFLoader::parseScale (std::shared_ptr<Shape> const& shape, std::istringstream& iss)
{
  auto scale = fetch_dvec3(iss);
  shape->scale(scale);
}

void 
SDFLoader::parseRotation (std::shared_ptr<Shape> const& shape, std::istringstream& iss)
{
  auto angle = fetch_primitive<double>(iss);
  auto rad = angle * M_PI / 180;
  auto axis = fetch_dvec3(iss);
  shape->rotate(rad, axis);
}

void 
SDFLoader::parseTranslation (std::shared_ptr<Shape> const& shape, std::istringstream& iss)
{
  auto translation = fetch_dvec3(iss);
  shape->translate(translation);
}

void 
SDFLoader::parseTransformation (std::istringstream& iss)
{
  auto shape = lookup_shape(fetch_primitive<std::string>(iss)); 
  auto transf_type = fetch_primitive<std::string>(iss);
  if (transf_type == "scale") {
    parseScale(shape, iss);
  } else if (transf_type == "rotate") {
    parseRotation(shape, iss);
  } else if (transf_type == "translate") {
    parseTranslation(shape, iss);
  }
}

void 
SDFLoader::parseDefinition (std::istringstream& iss)
{
  auto objecttype = fetch_primitive<std::string>(iss);
  if (objecttype == "shape") {
    auto shape = fetch_shape(iss);
    if(!shapes_.insert(std::make_pair(shape->name(), shape)).second) {
      throw std::runtime_error(std::string("shape " + shape->name() + " already exists"));
    }
  } else if (objecttype == "material") {
    auto material = fetch_material(iss);
    if(!materials_.insert(std::make_pair(material->name, material)).second) {
      throw std::runtime_error(std::string("material " + material->name + " already exists"));
    }
  }  else if (objecttype == "camera") {
    auto camera = fetch_camera(iss);
    if(!cameras_.insert(std::make_pair(camera->name(), camera)).second) {
      throw std::runtime_error(std::string("camera " + camera->name() + " already exists"));
    }
  } else if (objecttype == "light") {
    auto light = fetch_light(iss);
    if(!lights_.insert(std::make_pair(light->name(), light)).second) {
      throw std::runtime_error(std::string("light " + light->name() + " already exists"));
    }
  } else {
    throw std::runtime_error(std::string("no objecttype " + objecttype));
  }
}

void
SDFLoader::parseLine (std::string const& line) 
{
  std::istringstream iss(line);
  auto command = fetch_primitive<std::string>(iss);
  if (command == "define") {
    parseDefinition(iss);
  } else if (command == "render") {
    auto task = fetch_render_task(iss);
    tasks_.push_back(task);
  } else if (command == "transform") {
    parseTransformation(iss);
  }
}

std::shared_ptr<Scene> const& 
SDFLoader::scene() const{
  return scene_;
}

std::vector<RenderTask> const&
SDFLoader::tasks () const 
{
  return tasks_;
}

SDFLoader::SDFLoader (std::string const& sdfpath)
: scene_(std::make_shared<Scene>())
{
	std::ifstream infile;
	infile.open(sdfpath);
	std::string line;

	std::cout << "loading " << sdfpath << std::endl;
	while (std::getline(infile, line))
  {
    std::cout << "line retrieved: " << line << std::endl;

    parseLine(line);

  }
  
  // add all shapes from the "shape" map to the scene
  for (auto p: cameras_) {
    scene_->add_camera(p.second);
  }

  // add all shapes from the "shape" map to the scene
  for (auto p: shapes_) {
    scene_->add_shape(p.second);
  }

    // add all shapes from the "shape" map to the scene
  for (auto p: lights_) {
    scene_->add_light(p.second);
  }

    // add all shapes from the "shape" map to the scene
  for (auto p: materials_) {
    scene_->add_material(p.second);
  }  
}

    /*

    std::istringstream iss(line);

		//Material mat->

    std::string token_str;
    double token_double;

		// expect material name

		// annotation
		//if (token_str == # skip line)


    if (iss >> token_str)
    {
      std::cout << "iss >> token_str: " << token_str << std::endl;
      if (token_str=="define")
      {
        std::cout << "is define:" << token_str << std::endl;
                    // Hole nächstes Token
        iss >> token_str;

                    // Checke, ob mat->rial, shape, light, camera
        if(token_str == "material")
        {
          std::cout << "is material:" << token_str << std::endl;
                            // Instanciate a new Material Class Object
          auto mat = std::make_shared<Material>();
                                // expect std::string
          if (!(iss >> token_str)) {
            throw std::runtime_error();
          }
          std::cout << "material name: " << token_str << std::endl;

          mat->name = token_str;
          std::cout << "materialname:" << token_str << std::endl;
                            // expect ambient color

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ka.r = token_double;
          std::cout << "material_ka_r:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ka.g = token_double;
          std::cout << "material_ka_g:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ka.b = token_double;
          std::cout << "material_ka_b:" << token_double << std::endl;



                            // expect diffuse color

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->kd.r = token_double;
          std::cout << "material_kd_r:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->kd.g = token_double;
          std::cout << "material_kd_g:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->kd.b = token_double;
          std::cout << "material_kd_b:" << token_double << std::endl;

                            // expect specular color

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ks.r = token_double;
          std::cout << "material_ks_r:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ks.g = token_double;
          std::cout << "material_ks_g:" << token_double << std::endl;

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          mat->ks.b = token_double;
          std::cout << "material_ks_b:" << token_double << std::endl;


                            // expect specular exponent

                            // expect double
          if (!(iss >> token_double)) {
            throw std::runtime_error();
          }
          std::cout << "specexponent: " << token_double << std::endl;

          mat->specular_exp = token_double;

          scene_.add_mat(mat);
                            // std::cout << "materialslength: " << (scene_.get_materials()).size() << std::endl;
        }
        else if (token_str == "shape")
        {
          std::cout << "is shape: " << token_str << std::endl;

          iss >> token_str;
          if (!(iss >> token_str))
          {
            throw std::runtime_error();
          }
          else if (token_str == "box")
          {
           Box* box = new Box;

                               //expect name
                               //expect string
           if (!(iss >> token_str))
           {
             throw std::runtime_error();
           }
           box->setName(token_str);
                               //std::string boxname = token_str;


                               //expect min_.x
                               //expect double
           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMinx(token_double);
                               //double boxminx = token_double;

                               //expect min_.y
                               //expect double
           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMiny(token_double);
                               //double boxminy = token_double;

                               //expect min_.z
                               //expect double
           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMinz(token_double);
                               //glm::dvec3 boxmin (boxminx, boxminy, token_double);

           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMaxx(token_double);
                               //double boxmaxx = token_double;

           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMaxy(token_double);
                               //double boxmaxy = token_double;

           if (!(iss >> token_double))
           {
             throw std::runtime_error();
           }
           box->setMaxz(token_double);
                               //glm::dvec3 boxmax (boxmaxx, boxmaxy, token_double);

           if (!(iss >> token_str))
           {
             throw std::runtime_error();
           }




           bool foundmat = false;
           for (auto it = (scene_.get_materials()).begin() ; it != (scene_.get_materials()).end(); ++it)
           {

            if (((*it)->name).compare(token_str) == 0)
            {
              foundmat = true;
              box->setMaterial(*it);
                                            //std::shared_ptr<Material> boxmat = *it; // geht nicht,  wiesoo??
            }





          }
          if ( foundmat == false)
          {
            throw std::runtime_error();
          }

                                //Box(boxmin, boxmax, boxname, boxmat);
        }

        else if (token_str == "sphere")
        {
         Sphere* sphere = new Sphere;

                               //expect name
                               //expect string
         if (!(iss >> token_str))
         {
           throw std::runtime_error();
         }
         sphere->setName(token_str);

                               //expect center_.x
                               //expect double
         if (!(iss >> token_double))
         {
           throw std::runtime_error();
         }
         sphere->setcenter_x(token_double);

                               //expect center_.y
                               //expect double
         if (!(iss >> token_double))
         {
           throw std::runtime_error();
         }
         sphere->setcenter_y(token_double);

                               //expect center_.z
                               //expect double
         if (!(iss >> token_double))
         {
           throw std::runtime_error();
         }
         sphere->setcenter_z(token_double);

                               //expect radius
                               //expect double
         if (!(iss >> token_double))
         {
           throw std::runtime_error();
         }
         sphere->setradius(token_double);

                               //expect mat->rial name / color
                               //expect string
         if (!(iss >> token_str))
         {
           throw std::runtime_error();
         }

         bool foundmat = false;
         for (auto it = (scene_.get_materials()).begin() ; it != (scene_.get_materials()).end(); ++it)
         {

          if (((*it)->name).compare(token_str) == 0)
          {
            foundmat = true;
            sphere->setMaterial(*it);
          }



        }
        if ( foundmat == false)
        {
          throw std::runtime_error();
        }


      }


    }
    else if (token_str == "light")
                                    // Behandle die einzelnen Typen getrennt nach Typ
    {   

      std::cout << "is light: " << token_str << std::endl;
                            //Light* light = new Light;
      if (!(iss >> token_str))
      {
        throw std::runtime_error();
      }
      std::string lightname = token_str;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double position_x = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double position_y = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double position_z = token_double;
      glm::dvec3 position(position_x, position_y, position_z);

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
                            // ambientes licht wird anscheinenfd woanders  (scene) abgespeichert

      double ka_x = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }

      double ka_y = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }

      double ka_z = token_double;
      Color ka(ka_x, ka_y, ka_z);

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }

      double kd_x = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }

      double kd_y = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }

      double kd_z = token_double;

      Color kd(kd_x, kd_y, kd_z);

      auto light = std::make_shared<Light>(lightname, position, ka, kd);

      scene_.add_light(light);
    }

    else if (token_str == "camera")
    {
      std::cout << "is camera: " << token_str << std::endl;
                            //Camera* camera = new Camera();
      if (!(iss >> token_str))
      {
        throw std::runtime_error();
      }
      std::string cameraname = token_str;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double cameraangle = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double resolutionx = token_double;

      if (!(iss >> token_double))
      {
        throw std::runtime_error();
      }
      double resolutiony = token_double;

      Camera camera(cameraname, cameraangle, glm::ivec2(resolutionx, resolutiony));

      scene_.camera(camera);
    }
    else
    {
      std::cout << "not supported subtype: " << token_str << std::endl;
                                       // not supported subtype
      throw std::runtime_error();
    }
  }



  else if(token_str=="render")
  {
        // Do the render stuff
    std::cout << "is renderer: " << token_str << std::endl;
            //Renderer* renderer = new Renderer(640,780,"image.ppm");

    if (!(iss >> token_str))
    {
      throw std::runtime_error();
    }

    if (!(iss >> token_str))
    {
      throw std::runtime_error();
    }

    std::string filename = token_str;

    if (!(iss >> token_double))
    {
      throw std::runtime_error();
    }

    double width = token_double;

    if (!(iss >> token_double))
    {
      throw std::runtime_error();
    }


  }
		/*else if(token_str=="transform") // for eSDF (Extended SDF)
    {
      std::cout << "is transform: " << token_str << std::endl;
      if (token_str == "transform"){
                if (token_str == shapes.find(token_str);){ // wenn irgendein bereits bestehendes objekt aufgerufen wird, dann weiter

                }
              }
              else{
                iss >> token_str;
              }
            }

          }
        }

      }*/


//jedes shape auf hits prüfen, loop über size von shape container
//hit intersection vector
//vector sortienen , kürzest entfernte punkte finden
//gefundene Punkte speichern in vector oder list
// über vector loopen und intersect durchführen mit lichtquelle
//punkt liegt in schatten oder licht
//punkte mit farben abspeichern

/*Scene
SDFLoader::scene () const
{
	return scene_;
}
*/

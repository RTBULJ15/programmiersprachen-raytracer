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

SDFLoader::SDFLoader (std::string const& sdfpath)
: scene_()
{
	std::ifstream infile;
	infile.open(sdfpath);
	std::string line;

	std::cout << "loading " << sdfpath << std::endl;
	while (std::getline(infile, line))
        {
		std::cout << "line retrieved: " << line << std::endl;
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
                                throw std::exception();
                            }
                            std::cout << "material name: " << token_str << std::endl;

                            mat->name = token_str;

                            // expect ambient color

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ka.r = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ka.g = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ka.b = token_double;



                            // expect diffuse color

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->kd.r = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->kd.g = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->kd.b = token_double;

                            // expect specular color

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ks.r = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ks.g = token_double;

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            mat->ks.b = token_double;


                            // expect specular exponent

                            // expect double
                            if (!(iss >> token_double)) {
                                throw std::exception();
                            }
                            std::cout << "specexponent: " << token_double << std::endl;

                            mat->specular_exp = token_double;

                            (scene_.get_materials()).push_back(mat);
                            std::cout << "materialslength: " << (scene_.get_materials()).size() << std::endl;
                        }
                        else if (token_str == "shape")
                        {
                            std::cout << "is shape: " << token_str << std::endl;
                            if (!(iss >> token_str))
                                {
                                    throw std::exception();
                                }
                            else if (token_str == "box")
                            {
                               Box* box = new Box;

                               //expect name
                               //expect string
                               if (!(iss >> token_str))
                               {
                                   throw std::exception();
                               }
                               box->setName(token_str);

                               //expect min_.x
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMinx(token_double);

                               //expect min_.y
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMiny(token_double);

                               //expect min_.z
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMinz(token_double);

                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMaxx(token_double);

                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMaxy(token_double);

                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               box->setMaxz(token_double);

                               if (!(iss >> token_str))
                               {
                                   throw std::exception();
                               }




                                bool foundmat = false;
                                for (auto it = (scene_.get_materials()).begin() ; it != (scene_.get_materials()).end(); ++it)
                                {

                                    if (((*it)->name).compare(token_str) == 0)
                                        {
                                            foundmat = true;
                                            box->setMaterial(*it);
                                        }



                                }
                                if ( foundmat == false)
                                {
                                    throw std::exception();
                                }


                            }

                            else if (token_str == "sphere")
                            {
                               Sphere* sphere = new Sphere;

                               //expect name
                               //expect string
                               if (!(iss >> token_str))
                               {
                                   throw std::exception();
                               }
                               sphere->setName(token_str);

                               //expect center_.x
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               sphere->setcenter_x(token_double);

                               //expect center_.y
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               sphere->setcenter_y(token_double);

                               //expect center_.z
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               sphere->setcenter_z(token_double);

                               //expect radius
                               //expect double
                               if (!(iss >> token_double))
                               {
                                   throw std::exception();
                               }
                               sphere->setradius(token_double);

                               //expect mat->rial name / color
                               //expect string
                               if (!(iss >> token_str))
                               {
                                   throw std::exception();
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
                                    throw std::exception();
                                }


                            }


                        }
                        else if (token_str == "light")
                                    // Behandle die einzelnen Typen getrennt nach Typ
                        {
                            std::cout << "is light: " << token_str << std::endl;
                            Light* light = new Light;
                            if (!(iss >> token_str))
                            {
                                throw std::exception();
                            }
                            light-> setName(token_str);

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }
                            light-> setPosition_x(token_double);

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }
                            light-> setPosition_y(token_double);

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }
                            light-> setPosition_z(token_double);

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }
                            // ambientes licht wird anscheinenfd woanders  (scene) abgespeichert

                            //light.kd.r = token_double;

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }

                            //light.kd.g = token_double;

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }

                            //light.kd.b = token_double;

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }

                            //light.ks.r = token_double;

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }

                            //light.ks.g = token_double;

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }

                            //light.ks. = token_double;

                        }

                        else if (token_str == "camera")
                        {
                            std::cout << "is camera: " << token_str << std::endl;
                            Camera* camera = new Camera();
                            if (!(iss >> token_str))
                            {
                                throw std::exception();
                            }
                            camera->setname(token_str);

                            if (!(iss >> token_double))
                            {
                                throw std::exception();
                            }
                            camera->setangle(token_double);
                        }
                        else
                        {
                            std::cout << "not supported subtype: " << token_str << std::endl;
                                       // not supported subtype
                            throw std::exception();
                        }
            }
/**********************************************************************************/


/*************************************************************************************************/



		else if(token_str=="render")
        {
        // Do the render stuff
            std::cout << "is renderer: " << token_str << std::endl;
            Renderer* renderer = new Renderer(640,780,"image.ppm");

            if (!(iss >> token_str))
            {
                throw std::exception();
            }

            if (!(iss >> token_str))
            {
                throw std::exception();
            }

            renderer->setfilename(token_str);

            if (!(iss >> token_double))
            {
                throw std::exception();
            }

            renderer->setwidth(token_double);

            if (!(iss >> token_double))
            {
                throw std::exception();
            }

            renderer->setheight(token_double);

		}
		else if(token_str=="transform") // for eSDF (Extended SDF)
        {
            std::cout << "is transform: " << token_str << std::endl;

		}

        }
	}

}

/*Scene
SDFLoader::scene () const
{
	return scene_;
}
*/

# CMake generated Testfile for 
# Source directory: /opt/raytracer/2/programmiersprachen-raytracer
# Build directory: /opt/raytracer/2/programmiersprachen-raytracer/source
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(tests "/opt/raytracer/2/programmiersprachen-raytracer/source/build/Release/tests")
SUBDIRS(external/glfw-3.0.3)
SUBDIRS(framework)
SUBDIRS(source)
SUBDIRS(tests)

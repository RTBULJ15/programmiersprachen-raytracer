add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

add_executable(animation_maker animation_maker.cpp)

target_link_libraries(animation_maker ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(animation_maker glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS animation_maker DESTINATION .)

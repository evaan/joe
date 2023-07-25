cmake_minimum_required(VERSION 3.25)

project(joe)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

add_subdirectory(glfw)

set(joe main.cpp)

add_executable(joe WIN32 main.cpp)
target_link_libraries(joe ${OPENGL_LIBRARIES} glfw)
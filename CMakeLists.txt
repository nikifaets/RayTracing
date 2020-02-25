cmake_minimum_required (VERSION 3.0)
#set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Our project name
project (raytracer)

file(GLOB_RECURSE raytracer_SRC

	"src/*.h"
	"src/*.cpp"
)

#find_file(SDL2_INCLUDE_DIRS NAME SDL.h HINTS SDL2 PATH_SUFFIXES /usr)
#find_library(SDL2_LIBRARIES NAME SDL2)
find_package(SDL2 REQUIRED PATHS /usr/include)

#include_directories(${SDL2_INCLUDE_DIRS})

add_executable(raytracer ${raytracer_SRC})

# Linking SDL2 library with project.
target_link_libraries(raytracer SDL2::SDL2)


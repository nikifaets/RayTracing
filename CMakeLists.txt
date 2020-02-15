cmake_minimum_required (VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Our project name
project (framework)

add_executable(framework main.cpp Cube.cpp Object3D.cpp Camera.cpp MainWindow.cpp )


# For finding our SDL2 package!

find_file(SDL2_INCLUDE_DIRS NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARIES NAME SDL2)

#INCLUDE(FindPkgConfig)

# Searching SDL2 package.
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# Including our external library's directory for header files!
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

# Linking SDL2 library with our project.
target_link_libraries(framework ${SDL2_LIBRARIES})


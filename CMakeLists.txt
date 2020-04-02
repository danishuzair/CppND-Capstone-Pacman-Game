cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(PacMan src/main.cpp src/Renderer.cpp src/Game.cpp src/Game.h src/Controller.cpp src/Controller.h src/Pacman.cpp src/Pacman.h src/Ghost.cpp src/Ghost.h src/Intersection.cpp src/Intersection.h src/CreateTraversableArea.cpp src/CreateTraversableArea.h src/Street.cpp src/Street.h src/TrafficObject.cpp src/TrafficObject.h)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PacMan ${SDL2_LIBRARIES})

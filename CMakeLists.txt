set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

project(PACMAN)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(SOURCE_FILES src/main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_OPENCV REQUIRED IMPORTED_TARGET opencv)
pkg_search_module(PKG_X11 REQUIRED IMPORTED_TARGET x11)

add_executable(PacMan ${SOURCE_FILES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PacMan ${SDL2_LIBRARIES} PkgConfig::PKG_OPENCV PkgConfig::PKG_X11)

include_directories(src)
add_subdirectory(src)

target_link_libraries(PacMan Pacman_lib)

add_subdirectory(Google_tests)
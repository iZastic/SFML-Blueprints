cmake_minimum_required(VERSION 3.3)
project(SFML-Blueprints)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add SFML
set(SFML_ROOT ../../SFML-2.3.2)
find_package(SFML 2 REQUIRED system window graphics network audio)
# Detect and add Box2D
set(BOX2D_ROOT ../../Box2D-2.3.1)
find_package(Box2D REQUIRED)

include_directories(${SFML_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR})

add_subdirectory(Chapter-2)
add_subdirectory(Chapter-3)
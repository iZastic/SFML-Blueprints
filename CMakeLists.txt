cmake_minimum_required(VERSION 3.3)
set(EXECUTABLE_NAME "SFML-Blueprints")

project(${EXECUTABLE_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.hpp Game.cpp Game.hpp Player.cpp Player.hpp Action.cpp Action.hpp ActionTarget.cpp ActionTarget.hpp ActionMap.cpp ActionMap.hpp)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Detect and add SFML
set(SFML_ROOT ../../../SFML-2.3.2)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
cmake_minimum_required(VERSION 3.3)
set(EXECUTABLE_NAME "Chapter-3")

project(${EXECUTABLE_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Game.cpp
        Game.hpp
        ../Chapter-2/Player.cpp
        ../Chapter-2/Player.hpp
        ../Chapter-2/Action.cpp
        ../Chapter-2/Action.hpp
        ../Chapter-2/ActionTarget.cpp
        ../Chapter-2/ActionTarget.hpp
        ../Chapter-2/ActionMap.cpp
        ../Chapter-2/ActionMap.hpp
        ../Chapter-2/ResourceManager.hpp
        ../Chapter-2/Configuration.cpp
        ../Chapter-2/Configuration.hpp
)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
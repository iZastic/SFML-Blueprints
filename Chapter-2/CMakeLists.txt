cmake_minimum_required(VERSION 3.3)
set(EXECUTABLE_NAME "Chapter-2")

project(${EXECUTABLE_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Game.cpp
        Game.hpp
        Player.cpp
        Player.hpp
        Action.cpp
        Action.hpp
        ActionTarget.cpp
        ActionTarget.hpp
        ActionMap.cpp
        ActionMap.hpp
        ResourceManager.hpp
        Configuration.cpp
        Configuration.hpp
)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
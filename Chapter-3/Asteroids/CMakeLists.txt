set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

set(EXECUTABLE_NAME "Chapter-3_Asteroids")

set(FILES_HEADER
        ${INCROOT}/Game.hpp
        ${INCROOT}/Player.hpp
        ${INCROOT}/Enemy.hpp
        ${INCROOT}/Action.hpp
        ${INCROOT}/ActionTarget.hpp
        ${INCROOT}/ActionMap.hpp
        ${INCROOT}/ResourceManager.hpp
        ${INCROOT}/Configuration.hpp
        ${INCROOT}/World.hpp
        ${INCROOT}/Collision.hpp
        ${INCROOT}/Entity.hpp
        ${INCROOT}/Saucer.hpp
        ${INCROOT}/Utils.hpp
        ${INCROOT}/Meteor.hpp
        ${INCROOT}/Shoot.hpp
)

set(FILES_SRC
        ${SRCROOT}/main.cpp
        ${SRCROOT}/Game.cpp
        ${SRCROOT}/Player.cpp
        ${SRCROOT}/Enemy.cpp
        ${SRCROOT}/Action.cpp
        ${SRCROOT}/ActionTarget.cpp
        ${SRCROOT}/ActionMap.cpp
        ${SRCROOT}/Configuration.cpp
        ${SRCROOT}/World.cpp
        ${SRCROOT}/Collision.cpp
        ${SRCROOT}/Entity.cpp
        ${SRCROOT}/Saucer.cpp
        ${SRCROOT}/Meteor.cpp
        ${SRCROOT}/Shoot.cpp
)

add_executable(${EXECUTABLE_NAME} ${FILES_HEADER} ${FILES_SRC})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
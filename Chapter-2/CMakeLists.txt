set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

set(EXECUTABLE_NAME "Chapter-2")

set(FILES_HEADER
        ${INCROOT}/Game.hpp
        ${INCROOT}/Player.hpp
        ${INCROOT}/Action.hpp
        ${INCROOT}/ActionTarget.hpp
        ${INCROOT}/ActionMap.hpp
        ${INCROOT}/ResourceManager.hpp
        ${INCROOT}/Configuration.hpp
        )

set(FILES_SRC
        ${SRCROOT}/main.cpp
        ${SRCROOT}/Game.cpp
        ${SRCROOT}/Player.cpp
        ${SRCROOT}/Action.cpp
        ${SRCROOT}/ActionTarget.cpp
        ${SRCROOT}/ActionMap.cpp
        ${SRCROOT}/Configuration.cpp
        )

add_executable(${EXECUTABLE_NAME} ${FILES_HEADER} ${FILES_SRC})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
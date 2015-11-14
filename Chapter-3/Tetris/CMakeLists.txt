set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_NAME "Chapter-3_Tetris")

set(FILES_HEADER
        ${INCROOT}/Stats.hpp
        ${INCROOT}/Piece.hpp
        ${INCROOT}/Board.hpp
        ${INCROOT}/Game.hpp
        ${INCROOT}/Random.hpp
)

set(FILES_SRC
        ${SRCROOT}/main.cpp
        ${SRCROOT}/Stats.cpp
        ${SRCROOT}/Piece.cpp
        ${SRCROOT}/Board.cpp
        ${SRCROOT}/Game.cpp
)

add_executable(${EXECUTABLE_NAME} ${FILES_HEADER} ${FILES_SRC})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

set(EXECUTABLE_NAME "Chapter-4_HelloWorld")

set(FILES_HEADER
        ${INCROOT}/Converter.hpp
)

set(FILES_SRC
        ${SRCROOT}/main.cpp
)

add_executable(${EXECUTABLE_NAME} ${FILES_HEADER} ${FILES_SRC})

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${BOX2D_LIBRARY})
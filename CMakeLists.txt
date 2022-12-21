cmake_minimum_required(VERSION 3.15)
project(M1OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(M1OEP main.cpp Games.cpp Fighter.cpp CDoubleP.cpp C.cpp Java.cpp Python.cpp Attack.cpp)

add_executable(M2OEPTest Programming_Rumble_Testing.cpp Fighter.cpp CDoubleP.cpp C.cpp Java.cpp Python.cpp Attack.cpp)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib/x64")
endif (WIN32)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(graphics graphics.cpp rect.cpp shape.cpp circle.cpp quad.cpp Button.cpp bubble.cpp cube.cpp)
if (WIN32)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()
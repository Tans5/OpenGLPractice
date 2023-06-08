cmake_minimum_required(VERSION 3.17)
project(OpenGLPractice)

set(CMAKE_CXX_STANDARD 14)

# OpenGL Start
#find_library(OpenGL-lib OpenGL)
find_package(OpenGL REQUIRED)
# OpenGL End

# GLFW Start
add_library(
        libglfw3
        SHARED
        IMPORTED
        include/triangle.h)
set_target_properties( libglfw3
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/lib-arm64/libglfw.3.dylib )

add_library(
        libglfw3.a
        STATIC
        IMPORTED
)
set_target_properties( libglfw3.a
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/lib-arm64/libglfw3.a)

# GLFW End

add_executable(OpenGLPractice
        main.cpp
        src/glad.c
        src/triangle.cpp)

target_include_directories(
        OpenGLPractice PUBLIC
        include
)
target_link_libraries(
        OpenGLPractice
        OpenGL::GL
        libglfw3
        libglfw3.a
)
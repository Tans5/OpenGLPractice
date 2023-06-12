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
        IMPORTED)
set_target_properties( libglfw3
        PROPERTIES IMPORTED_LOCATION
       ${CMAKE_CURRENT_SOURCE_DIR}/libs/mac/lib-arm64/libglfw.3.dylib
#        ${CMAKE_CURRENT_SOURCE_DIR}/libs/linux/lib-x86_64/libglfw.so.3.4
        )

#add_library(
#        libglfw3.a
#        STATIC
#        IMPORTED
#)
#set_target_properties( libglfw3.a
#        PROPERTIES IMPORTED_LOCATION
#        libs/mac/lib-arm64/libglfw3.a)

# GLFW End

#OpenGLPractice Start
add_executable(OpenGLPractice
        main.cpp
        src/glad.c
        src/triangle.cpp
#        src/glad_linux.c
        src/glad.c src/image_load.cpp src/cube.cpp src/compile_shader_program.cpp)

target_include_directories(
        OpenGLPractice PUBLIC
        include
)
target_link_libraries(
        OpenGLPractice
        OpenGL::GL
        libglfw3)
#OpenGLPractice End

#MatrixTest Start
add_executable(MatrixTest
        matrixTest.cpp)
target_include_directories(
        MatrixTest PUBLIC
        include
)
#MatrixTest End
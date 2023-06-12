//
// Created by pengcheng.tan on 2023/6/12.
//

#ifndef OPENGLPRACTICE_COMPILE_SHADER_PROGRAM_H
#define OPENGLPRACTICE_COMPILE_SHADER_PROGRAM_H

#include "glad/glad.h"

const GLuint SHADER_COMPILE_FAIL = -1;

GLuint compileShaderProgram(const char * vertexShaderSource, const char * fragmentShaderSource);

#endif //OPENGLPRACTICE_COMPILE_SHADER_PROGRAM_H

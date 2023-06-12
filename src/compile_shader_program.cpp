//
// Created by pengcheng.tan on 2023/6/12.
//
#include "compile_shader_program.h"
#include <cstdio>

/**
 * 编译着色器程序
 * @param vertexShaderSource 顶点着色器源码
 * @param fragmentShaderSource 片段作色器源码
 * @return 成功返回着色器程序，失败返回 -1
 */
GLuint compileShaderProgram(const char * vertexShaderSource, const char * fragmentShaderSource) {
    // 编译顶点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    GLint vertexCompileResult;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexCompileResult);
    if (!vertexCompileResult) {
        GLchar log[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, log);
        printf("Compile vertex shader fail: %s \n", log);
        glDeleteShader(vertexShader);
        return SHADER_COMPILE_FAIL;
    }

    // 编译片段着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    GLint fragmentCompileResult;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentCompileResult);
    if (!fragmentCompileResult) {
        GLchar log[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, log);
        printf("Compile fragment shader fail: %s \n", log);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return SHADER_COMPILE_FAIL;
    }

    // 链接顶点着色器和片段着色器
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    GLint programLinkResult;
    glGetProgramiv(program, GL_LINK_STATUS, &programLinkResult);
    if (!programLinkResult) {
        GLchar  log[512];
        glGetProgramInfoLog(program, 512, NULL, log);
        printf("Link program fail: %s", log);
        return SHADER_COMPILE_FAIL;
    }
    printf("Create shader program success. \n");
    return program;
}


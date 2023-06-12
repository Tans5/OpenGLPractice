//
// Created by pengcheng.tan on 2023/6/8.
//

#ifndef OPENGLPRACTICE_TRIANGLE_H
#define OPENGLPRACTICE_TRIANGLE_H
#include "image_load.h"

DecodedImage * getImage1Data();

DecodedImage * getImage2Data();

GLuint createTriangleProgram();

void drawTriangle();

#endif //OPENGLPRACTICE_TRIANGLE_H

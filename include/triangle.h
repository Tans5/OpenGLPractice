//
// Created by pengcheng.tan on 2023/6/8.
//

#ifndef OPENGLPRACTICE_TRIANGLE_H
#define OPENGLPRACTICE_TRIANGLE_H

#endif //OPENGLPRACTICE_TRIANGLE_H

typedef struct {
    unsigned char* data;
    int width;
    int height;
    int channels;
} DecodedImage;

DecodedImage * getImage1Data();

DecodedImage * getImage2Data();

GLuint createTriangleProgram();

void drawTriangle();

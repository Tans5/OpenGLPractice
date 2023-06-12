//
// Created by pengcheng.tan on 2023/6/12.
//

#ifndef OPENGLPRACTICE_IMAGE_LOAD_H
#define OPENGLPRACTICE_IMAGE_LOAD_H
typedef struct {
    unsigned char* data;
    int width;
    int height;
    int channels;
} DecodedImage;

DecodedImage *getImageData(const char * path);
#endif //OPENGLPRACTICE_IMAGE_LOAD_H

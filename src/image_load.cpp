//
// Created by pengcheng.tan on 2023/6/12.
//
#include <stb_image.h>
#include "image_load.h"

DecodedImage *getImageData(const char * path) {
    int width, height, channels;
    unsigned char *data = stbi_load(path, &width, &height, &channels, 0);
    auto decodedImage = new DecodedImage;
    decodedImage -> data = data;
    decodedImage -> width = width;
    decodedImage -> height = height;
    decodedImage -> channels = channels;
    return decodedImage;
}


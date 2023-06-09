//
// Created by pengcheng.tan on 2023/6/9.
//
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stdio.h"
#include "iostream"

int main() {
    glm::vec4 vec4 = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    // 4 x 4 单位矩阵
    glm::mat4 transform = glm::mat4(1.0f);
    // x 和 y 都放大2倍
    transform = glm::scale(transform, glm::vec3(2.0f, 2.0f, 0.0f));
    // 平移 x 1，y 1
    transform = glm::translate(transform, glm::vec3(1.0f, 1.0f, 0.0f));
    // 沿着 z 轴，旋转 90 度.
    transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    vec4 = transform * vec4;
    std::cout << vec4.x << " " << vec4.y << " " << vec4.z << std::endl;
    return 0;
}

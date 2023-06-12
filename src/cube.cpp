//
// Created by pengcheng.tan on 2023/6/12.
//
#include "cube.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "triangle.h"
#include "math.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// 顶点着色器源码
const char *cubeVertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n" // 点坐标
                                 "layout (location = 1) in vec2 aTexCoord;\n" // 纹理坐标
                                 "out vec2 TexCoord;" // 输出纹理坐标
                                 // 以下 uniform 是各种转换
                                 "uniform mat4 transform;\n"
                                 "uniform mat4 model;\n"
                                 "uniform mat4 view;\n"
                                 "uniform mat4 projection;\n"
                                 "void main()\n"
                                 "{ \n"
                                 "      glPosition = projection * view * model * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "      TexCoord = aTextCoord;\n"
                                 "} \n";


// 片段着色器源码
const char *cubeFragmentShaderSource = "#version 330 core\n"
                                   "in vec2 TexCoord;\n" // 输入纹理坐标
                                   "out vec4 FragColor;\n" // 输出颜色
                                   "uniform sampler2D Texture;\n" // 渲染纹理
                                   "void main()\n"
                                   "{ \n"
                                   "    FragColor = texture(Texture, TexCoord);\n"
                                   "} \n";

void drawCube() {

}


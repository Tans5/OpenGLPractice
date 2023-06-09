//
// Created by pengcheng.tan on 2023/6/8.
//

#include <glad/glad.h>
#include "OpenGL/OpenGL.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "triangle.h"
#include "math.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// 顶点着色器 GLSL 源码
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n" // 位置, 顶点着色器固定要加上 layout (location = 0)
                                 "layout (location = 1) in vec3 aColor;\n" // 颜色
                                 "layout (location = 2) in vec2 aTexCoord;\n"
                                 "out vec4 pColor;\n"
                                 "out vec2 TexCoord;\n"
                                 "uniform mat4 transform;\n"
                                 "uniform mat4 model;\n"
                                 "uniform mat4 view;\n"
                                 "uniform mat4 projection;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = projection * view * model * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "   pColor = vec4(aColor, 1.0);\n"
                                 "   TexCoord = aTexCoord;\n"
                                 "}\0";

// 片段着色器 GLSL 源码
const char *fragmentShaderSource = "#version 330 core\n"
                                   "in vec4 pColor;\n"
                                   "in vec2 TexCoord;\n"
                                   "uniform vec4 myColor = vec4(0.0, 1.0, 0.0, 1.0);\n" // 全局变量
                                   "uniform sampler2D Texture;\n"
                                   "uniform sampler2D Texture2;\n"
                                   "out vec4 FragColor;\n" // 输出变量
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = mix(texture(Texture, TexCoord), texture(Texture2, TexCoord), 0.5) * myColor;\n"
//                                    "     FragColor = texture(Texture, TexCoord);"
                                   "}\n";

const GLuint FAIL = -1;

GLuint programGlobal = -1;

DecodedImage *textureImage1Global = NULL; // 纹理图片
DecodedImage *textureImage2Global = NULL; // 纹理图片

/**
 * 生成三角形的 Shader Program.
 * @return 成功返回 三角形 program，错误返回 -1
 */
GLuint createTriangleProgram() {
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
        return FAIL;
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
        return FAIL;
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
        return FAIL;
    }
    printf("Create shader program success. \n");
    programGlobal = program;
    return program;
}

/**
 * 绘制三角形
 */
void drawTriangle() {
    if (programGlobal == FAIL) {
        createTriangleProgram();
    }
    if (programGlobal == FAIL) {
        return;
    }

    if (textureImage1Global == NULL) {
        getImage1Data();
    }
    if (textureImage1Global == NULL) {
        return;
    }

    if (textureImage2Global == NULL) {
        getImage2Data();
    }
    if (textureImage2Global == NULL) {
        return;
    }

    // 坐标是从 -1 到 1
    float vertices[] = {
            // 坐标(position 0)  // 颜色 (position 1) // 纹理坐标
            0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // 右上角
            0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // 右下角
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // 左下角
            -0.5f, 0.5f, 0.0f,  0.5f, 0.5f, 0.5f,   0.0f, 0.0f    // 左上角
    };

    // 顶点缓冲对象：Vertex Buffer Object，VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);
    // 顶点数组对象：Vertex Array Object，VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 元素缓冲对象：Element Buffer Object，EBO 或 索引缓冲对象 Index Buffer Object，IBO
    GLuint EBO;
    glGenBuffers(1, &EBO);


    // 绑定数据到 VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 设置顶点属性
    // 坐标
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // 颜色
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // 纹理
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // 使用编译好的渲染程序
    glUseProgram(programGlobal);
    float timeValue = glfwGetTime();
    // 更新uniform颜色
    float redValue = cos(timeValue) / 2.0f + 0.5f;
    float greenValue = sin(timeValue) / 2.0f + 0.5f;
    float blueValue = redValue + greenValue / 2;
    int vertexColorLocation = glGetUniformLocation(programGlobal, "myColor");
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

    // 3D 矩阵变换
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glUniformMatrix4fv(glGetUniformLocation(programGlobal, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(programGlobal, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(programGlobal, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    // 坐标变换
    glm::mat4 transform = glm::mat4(1.0f);
    // 放缩
//    float scale = abs(cos(timeValue)) + 0.5f;
//    transform = glm::scale(transform, glm::vec3(scale, scale, 0));
    // 旋转
    transform = glm::rotate(transform, glm::radians(timeValue * 100), glm::vec3(1.0f, 0.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(programGlobal, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

    // 纹理处理
    // 纹理1
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureImage1Global->width, textureImage1Global->height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 textureImage1Global->data);

    // 纹理2
    GLuint texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureImage2Global->width, textureImage2Global->height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 textureImage2Global->data);

    glActiveTexture(GL_TEXTURE0); // 激活纹理
    glActiveTexture(GL_TEXTURE1);
    glUniform1i(glGetUniformLocation(programGlobal, "Texture"), 1); // 绑定纹理到片段着色器到 Texture 变量
    glUniform1i(glGetUniformLocation(programGlobal, "Texture2"), 0); // 绑定纹理到片段着色器到 Texture2 变量

//    glBindVertexArray(VAO);

    // 绘制，第一个参数表示 图元，第二个参数索引开始位置，第三个参数顶点个数
    // glDrawArrays(GL_TRIANGLES, 0, 3);

    unsigned int indices[] = {
            // 注意索引从0开始!
            // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
            // 这样可以由下标代表顶点组合成矩形
            0, 1, 3, // 第一个三角形
            1, 2, 3,  // 第二个三角形
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 不填充，
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}

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

DecodedImage *getImage1Data() {
    auto decodedImage = getImageData("../test.png");
    textureImage1Global = decodedImage;
    return decodedImage;
}

DecodedImage *getImage2Data() {
    auto decodedImage = getImageData("../test2.png");
    textureImage2Global = decodedImage;
    return decodedImage;
}
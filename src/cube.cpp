//
// Created by pengcheng.tan on 2023/6/12.
//
#include "cube.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "compile_shader_program.h"
#include "image_load.h"

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
                                 "      gl_Position = projection * view * model * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//                                   "      gl_Position = vec4(aPos, 1.0);\n"
                                 "      TexCoord = aTexCoord;\n"
                                 "} \n";


// 片段着色器源码
const char *cubeFragmentShaderSource = "#version 330 core\n"
                                   "in vec2 TexCoord;\n" // 输入纹理坐标
                                   "out vec4 FragColor;\n" // 输出颜色
                                   "uniform sampler2D Texture;\n" // 渲染纹理
                                   "void main()\n"
                                   "{ \n"
                                   "    FragColor = texture(Texture, TexCoord);\n"
//                                     "FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
                                   "} \n";

GLint cubeProgram = SHADER_COMPILE_FAIL;
DecodedImage * shaderImage = NULL;


void createCubeProgram() {
    cubeProgram = compileShaderProgram(cubeVertexShaderSource, cubeFragmentShaderSource);
}

void loadImageData() {
    shaderImage = getImageData("../container.jpeg");
}

typedef struct {
    GLuint VBO;
    GLuint VAO;
    GLuint texture;
} DrawCubeBuffer;

DrawCubeBuffer * drawCubeBuffer = NULL;

void createDrawCubeBuffer() {
    if (shaderImage == NULL) {
        loadImageData();
    }
    float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    // 正方体 6 个面，每个面 2 个三角形，每个三角形 3 个点，所以一共 36 个点
//    float vertices[] = {
//            // 坐标               // 纹理坐标
//            0.5f, 0.5f, 0.0f,    1.0f, 0.0f, // 底面 右上角
//            0.5f, -0.5f, 0.0f,   1.0f, 1.0f, // 底面 右下角
//            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, // 底面 左下角
//            -0.5f, 0.5f, 0.0f,   0.0f, 0.0f, // 底面 左上角
//
//            0.5f, 0.5f, 1.0f,    1.0f, 0.0f, // 上面 右上角
//            0.5f, -0.5f, 1.0f,   1.0f, 1.0f, // 上面 右下角
//            -0.5f, -0.5f, 1.0f,  0.0f, 1.0f, // 上面 左下角
//            -0.5f, 0.5f, 1.0f,   0.0f, 0.0f, // 上面 左上角
//    };

//    // 12 个三角形
//    unsigned int indices[] = {
//            // 底
//            0, 1, 3,
//            1, 2, 3,
//
//            // 上
//            4, 5, 7,
//            5, 6, 7,
//
//            // 前
//            1, 2, 5,
//            2, 5, 6,
//
//            // 后
//            0, 3, 4,
//            3, 4, 7,
//
//            // 左
//            2, 3, 7,
//            2, 6, 7,
//
//            // 右
//            0, 1, 4,
//            1, 4, 5,
//    };

    GLuint VBO;
    glGenBuffers(1, &VBO);

    // 顶点数组对象
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 设置顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 纹理处理
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
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, shaderImage->width, shaderImage->height, 0, GL_RGB, GL_UNSIGNED_BYTE, shaderImage->data);

    // 元素缓冲对象
//    GLuint EBO;
//    glGenBuffers(1, &EBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    auto buffer = new DrawCubeBuffer;
    buffer->VAO = VAO;
    buffer->VBO = VBO;
    buffer->texture = texture;
    drawCubeBuffer = buffer;
}

void drawCube() {
    if (cubeProgram == SHADER_COMPILE_FAIL) {
        createCubeProgram();
    }
    if (cubeProgram == SHADER_COMPILE_FAIL) {
        return;
    }
    if (drawCubeBuffer == NULL) {
        createDrawCubeBuffer();
    }

    // Z 缓冲
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 使用程序
    glUseProgram(cubeProgram);

    float timeValue = glfwGetTime();
    // 3D 矩阵变换
//    glm::mat4 model = glm::mat4(1.0f);
//    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    float radius = 10.0f;
    float camX = sin(timeValue) * radius;
    float camZ = cos(timeValue) * radius;
    // 第一个参数相机位置，第二个参数眼睛注释的点，第三个参数相机的旋转方向
    view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//    glUniformMatrix4fv(glGetUniformLocation(cubeProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(cubeProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(cubeProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glm::mat4 transform = glm::mat4(1.0f);
    // 旋转
    transform = glm::rotate(transform, glm::radians(timeValue * 100), glm::vec3(0.5f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(cubeProgram, "transform"), 1, GL_FALSE, glm::value_ptr(transform));
//    glBindTexture(GL_TEXTURE_2D, drawCubeBuffer->texture);

    glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawCubeBuffer->VAO);

    for(unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        glUniformMatrix4fv(glGetUniformLocation(cubeProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
//    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);

}


#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include "glm/ext.hpp"
#include <cstdio>
#include <iostream>

const float DEPTH = -10;

const float PI = 3.14;

void drawTheBox(glm::vec2 center, glm::vec2 size){
    float halfXEdge = size.x;
    float halfYEdge = size.y;
    glBegin(GL_TRIANGLES);
    glVertex3f(   center.x - halfXEdge,  center.y - halfYEdge, DEPTH);
    glVertex3f( center.x - halfXEdge, center.y + halfYEdge, DEPTH);
    glVertex3f(center.x + halfXEdge, center.y - halfYEdge, DEPTH);
    glVertex3f(   center.x + halfXEdge,  center.y + halfYEdge, DEPTH);
    glVertex3f( center.x - halfXEdge, center.y + halfYEdge, DEPTH);
    glVertex3f(center.x + halfXEdge, center.y - halfYEdge, DEPTH);
    glEnd();
}

void drawTheCircle(glm::vec2 center, float radius){
    int segments = 30;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x, center.y, DEPTH);
    for (int i = 0; i <= segments; i++){
        float angleValue = i * (2 * PI) / segments;
        float axisX = glm::sin(angleValue) * radius + center.x;
        float axisY = glm::cos(angleValue) * radius + center.y;
        glVertex3f(axisX, axisY, DEPTH);
    }


    glEnd();
}
int main()
{
    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwDefaultWindowHints();

    GLFWwindow* window = glfwCreateWindow(620, 620, "Boxes",
                                          nullptr, nullptr);
    if(window == nullptr) {
        std::cerr << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwShowWindow(window);

    // Важно! Не эквивалентно glEnable(GL_DEPTH_TEST | GL_DOUBLEBUFFER)
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DOUBLEBUFFER);
    glDepthFunc(GL_LESS);

    glClearColor(0, 0, 0, 1);

    glm::mat4 m = glm::perspective(45.0f, 4.0f / 3.0f, 1.0f, 100.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(m));
    glm::vec2 centerOfBox(-0.5, 0.0);
    while(glfwWindowShouldClose(window) == GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor4f(1, 0, 0, 1);
//        drawTheBox(centerOfBox, glm::vec2(.25, .7));
        drawTheCircle(centerOfBox, 2.0);
        centerOfBox = centerOfBox + glm::vec2(0.0, -0.01);

//        drawTheBox(glm::vec2(0.5, 0.0), glm::vec2(0.5, 0.3));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
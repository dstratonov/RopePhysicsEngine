#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include "glm/ext.hpp"
#include "Scene/Scene.h"
#include <iostream>
#include <vector>

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

    Scene::createNewJoint(glm::vec2(0.0, 0.0));
    Scene::createNewJoint(glm::vec2(2.0, 0.0), 5.0f);
    Scene::createNewLineCollider(glm::vec2(10, 1), glm::vec2(-10, -5));
    Scene::createNewLineCollider(glm::vec2(7, -5), glm::vec2(7, 5));
    Scene::createNewLineCollider(glm::vec2(-3, -5), glm::vec2(-3, 5));
    Scene::createNewLineCollider(glm::vec2(-2, -5), glm::vec2(-2, -2.4));


    while(glfwWindowShouldClose(window) == GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor4f(1, 0, 0, 1);
        Scene::update();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
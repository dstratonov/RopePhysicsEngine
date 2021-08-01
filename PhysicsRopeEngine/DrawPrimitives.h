#pragma once
#include <GL/glut.h>

namespace Primitives {
    const float DEPTH = -10;

    const float PI = 3.14;

    void drawTheBox(glm::vec2 center, glm::vec2 size) {
        float halfXEdge = size.x;
        float halfYEdge = size.y;
        glBegin(GL_TRIANGLES);
        glVertex3f(center.x - halfXEdge, center.y - halfYEdge, DEPTH);
        glVertex3f(center.x - halfXEdge, center.y + halfYEdge, DEPTH);
        glVertex3f(center.x + halfXEdge, center.y - halfYEdge, DEPTH);
        glVertex3f(center.x + halfXEdge, center.y + halfYEdge, DEPTH);
        glVertex3f(center.x - halfXEdge, center.y + halfYEdge, DEPTH);
        glVertex3f(center.x + halfXEdge, center.y - halfYEdge, DEPTH);
        glEnd();
    }

    void drawTheCircle(glm::vec2 center, float radius) {
        int segments = 30;
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(center.x, center.y, DEPTH);
        for (int i = 0; i <= segments; i++) {
            float angleValue = i * (2 * PI) / segments;
            float axisX = glm::sin(angleValue) * radius + center.x;
            float axisY = glm::cos(angleValue) * radius + center.y;
            glVertex3f(axisX, axisY, DEPTH);
        }


        glEnd();
    }
}
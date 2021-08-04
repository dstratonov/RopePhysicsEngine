#include "DrawPrimitives.h"


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

void drawTheCircle(glm::vec2 center, float radius, glm::vec3 color) {
    int segments = 30;
    glColor4f(color.x, color.y, color.z, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(center.x, center.y, DEPTH);
    for (int i = 0; i <= segments; i++) {
        float angleValue = i * (2 * PI) / segments;
        float axisX = glm::sin(angleValue) * radius + center.x;
        float axisY = glm::cos(angleValue) * radius + center.y;
        glVertex3f(axisX, axisY, DEPTH);
    }
    glEnd();
    glColor4f(1, 0, 0, 1);
}

void drawTheLine(glm::vec2 startPoint, glm::vec2 endPoint){
    glBegin(GL_LINES);
    glVertex3f(startPoint.x, startPoint.y, DEPTH);
    glVertex3f(endPoint.x, endPoint.y, DEPTH);
    glEnd();
}



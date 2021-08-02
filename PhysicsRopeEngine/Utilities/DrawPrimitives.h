#pragma once

#include <GL/glut.h>
#include "glm/ext.hpp"


const float DEPTH = -10;

const float PI = 3.14;

void drawTheBox(glm::vec2 center, glm::vec2 size);

void drawTheCircle(glm::vec2 center, float radius);

void drawTheLine(glm::vec2 startPoint, glm::vec2 endPoint);
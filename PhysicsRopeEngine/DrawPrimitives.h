#pragma once

#include <GL/glut.h>
#include "glm/ext.hpp"


namespace Primitives {
    const float DEPTH = -10;

    const float PI = 3.14;

    void drawTheBox(glm::vec2 center, glm::vec2 size);

    void drawTheCircle(glm::vec2 center, float radius);
}
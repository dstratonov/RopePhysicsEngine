#pragma once
#include "glm/ext.hpp"
#include "../BaseClasses/Collider.h"
#include "../Utilities/DrawPrimitives.h"
class LineCollider : public Collider, public RenderedObject {
public:
    LineCollider(glm::vec2 lineStart, glm::vec2 lineEnd);
    void collision(Joint* joint);
    void render();
    float a;
    float b;
    float c;
    glm::vec2 lineStart;
    glm::vec2 lineEnd;
};


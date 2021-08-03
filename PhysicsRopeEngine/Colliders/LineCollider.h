#pragma once
#include "glm/ext.hpp"
#include "../BaseClasses/Collider.h"
#include "../Utilities/DrawPrimitives.h"
#include "../BaseClasses/RenderedObject.h"

class LineCollider : public Collider, public RenderedObject {
public:
    LineCollider(glm::vec2 lineStart, glm::vec2 lineEnd);
    void render();
    glm::vec2 getPosition();
    bool isColliding(Collider* collider, glm::vec2& outVector);
    float distanceToCollider(glm::vec2 position);
    float getRadius();
    void addColliderForce(glm::vec2 forceVector);
    glm::vec2 lineStart;
    glm::vec2 lineEnd;
};


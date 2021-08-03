#pragma once
#include "glm/ext.hpp"

class Collider {
public:
    void collision(Collider* joint);
    virtual glm::vec2 getPosition() = 0;
    virtual bool isColliding(Collider* collider, glm::vec2& outVector) = 0;
    virtual float distanceToCollider(glm::vec2 position) = 0;
    virtual float getRadius() = 0;
    virtual void addColliderForce(glm::vec2 forceVector) = 0;

};


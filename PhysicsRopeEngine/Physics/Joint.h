#pragma once

#include "glm/ext.hpp"
#include "../BaseClasses/RenderedObject.h"
#include "../BaseClasses/UpdatedObject.h"
#include "../BaseClasses/Collider.h"

const float DEFAULT_JOINT_RADIUS = 0.5;
const float PHYSIC_STEP = 0.01;
const glm::vec2 GRAVITY(0.0, -0.1);


class Joint : public UpdatedObject, public RenderedObject, public Collider{
public:
    Joint(glm::vec2 initialPosition);
    Joint(glm::vec2 initialPosition, float mass);
    glm::vec2 getPosition();
    glm::vec2 getVelocity();
    float getRadius();
    void addColliderForce(glm::vec2 force);
    void update();
    void render();

    bool isColliding(Collider* collider, glm::vec2& outVector);
    float distanceToCollider(glm::vec2 position);
private:
    glm::vec2 mVelocity;
    glm::vec2 mPosition;
    float mMass = 1.0f;
    glm::vec2 mColliderForce;
};

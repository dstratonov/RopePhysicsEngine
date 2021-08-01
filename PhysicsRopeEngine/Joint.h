#pragma once

#include "glm/ext.hpp"

const float DEFAULT_JOINT_RADIUS = 0.5;
const float PHYSIC_STEP = 0.01;
const glm::vec2 GRAVITY(0.0, -0.1);


class Joint{
public:
    Joint(glm::vec2 initialPosition) : mPosition(initialPosition){}
    Joint(glm::vec2 initialPosition, float mass) : mPosition(initialPosition), mMass(mass){}
    void update();
    void reDraw();
private:
    glm::vec2 mVelocity;
    glm::vec2 mPosition;
    float mMass = 1.0f;
};

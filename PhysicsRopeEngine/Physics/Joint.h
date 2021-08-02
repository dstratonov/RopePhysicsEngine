#pragma once

#include "glm/ext.hpp"
#include "../BaseClasses/RenderedObject.h"
#include "../BaseClasses/UpdatedObject.h"
#include "../Scene/Scene.h"

const float DEFAULT_JOINT_RADIUS = 0.5;
const float PHYSIC_STEP = 0.01;
const glm::vec2 GRAVITY(0.0, -0.1);


class Joint : public UpdatedObject, public RenderedObject{
public:
    Joint(glm::vec2 initialPosition, Scene* scene);
    Joint(glm::vec2 initialPosition, float mass, Scene* scene);
    void update();
    void render();
private:
    glm::vec2 mVelocity;
    glm::vec2 mPosition;
    float mMass = 1.0f;
};

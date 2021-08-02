#include "Joint.h"
#include "../Utilities/DrawPrimitives.h"

Joint::Joint(glm::vec2 initialPosition, Scene* scene) : mPosition(initialPosition), UpdatedObject(scene),
                                                        RenderedObject(scene){
}

Joint::Joint(glm::vec2 initialPosition, float mass, Scene* scene) : mPosition(initialPosition), mMass(mass), UpdatedObject(scene),
                                                        RenderedObject(scene){
}

void Joint::update() {
    glm::vec2 forces = GRAVITY;
    forces *= PHYSIC_STEP;

    if ((mPosition.y - DEFAULT_JOINT_RADIUS) < -2.0){
        forces += (glm::vec2(0.0, 1.0) * (-2 - (mPosition.y - DEFAULT_JOINT_RADIUS)));
    }

    mVelocity = mVelocity + forces / mMass;
    mVelocity *= 0.99;
    mPosition = mPosition + mVelocity;
}

void Joint::render() {
    drawTheCircle(mPosition, DEFAULT_JOINT_RADIUS);
}
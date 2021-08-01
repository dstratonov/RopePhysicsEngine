#include "Joint.h"
#include "DrawPrimitives.h"

Joint::Joint(glm::vec2 initialPosition, Scene* scene) : mPosition(initialPosition), UpdatedObject(scene),
                                                        RenderedObject(scene){
}

Joint::Joint(glm::vec2 initialPosition, float mass, Scene* scene) : mPosition(initialPosition), mMass(mass), UpdatedObject(scene),
                                                        RenderedObject(scene){
}

void Joint::update() {
    mVelocity = mVelocity + (GRAVITY * PHYSIC_STEP) / mMass;
    mPosition = mPosition + mVelocity;
}

void Joint::render() {
    Primitives::drawTheCircle(mPosition, DEFAULT_JOINT_RADIUS);
}
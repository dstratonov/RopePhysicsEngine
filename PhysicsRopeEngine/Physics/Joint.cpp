#include "Joint.h"
#include "../Utilities/DrawPrimitives.h"

Joint::Joint(glm::vec2 initialPosition) : mPosition(initialPosition){
}

Joint::Joint(glm::vec2 initialPosition, float mass) : mPosition(initialPosition), mMass(mass){
}

void Joint::update() {
    glm::vec2 forces = GRAVITY;
    forces *= PHYSIC_STEP;
    forces += mColliderForce;

    mVelocity = mVelocity + forces / mMass;
    mVelocity *= 0.99;
    mPosition = mPosition + mVelocity;
    mColliderForce.x = 0.0f;
    mColliderForce.y = 0.0f;
}

void Joint::render() {
    drawTheCircle(mPosition, DEFAULT_JOINT_RADIUS);
}

glm::vec2 Joint::getPosition() {
    return mPosition;
}

glm::vec2 Joint::getVelocity(){
    return mVelocity;
}

float Joint::getRadius() {
    return DEFAULT_JOINT_RADIUS;
}

void Joint::addColliderForce(glm::vec2 force) {
    mColliderForce += force;
}
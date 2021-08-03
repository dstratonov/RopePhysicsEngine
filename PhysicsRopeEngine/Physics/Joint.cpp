#include "Joint.h"
#include "../Utilities/DrawPrimitives.h"

Joint::Joint(glm::vec2 initialPosition) : mPosition(initialPosition){
}

Joint::Joint(glm::vec2 initialPosition, float mass) : mPosition(initialPosition), mMass(mass){
}

float Joint::distanceToCollider(glm::vec2 position) {
    return glm::distance(position, mPosition);
}

bool Joint::isColliding(Collider *collider, glm::vec2 &outVector) {
    glm::vec2 jointPosition = collider->getPosition();
    float jointRadius = collider->getRadius();
    float distanceToCollider = glm::distance(jointPosition, mPosition);

    if ((distanceToCollider - getRadius()) < jointRadius){
        glm::vec2 forceVector = jointPosition - mPosition;
        glm::normalize(forceVector);
        forceVector *= (jointRadius - (distanceToCollider - getRadius())) * 1.0f;
        outVector = forceVector;
        collider->addColliderForce(forceVector);
        return true;
    }
    return false;
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
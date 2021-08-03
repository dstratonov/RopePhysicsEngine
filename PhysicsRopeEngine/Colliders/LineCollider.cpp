
#include "LineCollider.h"


LineCollider::LineCollider(glm::vec2 lineStart, glm::vec2 lineEnd) {
    this->lineStart = lineStart;
    this->lineEnd = lineEnd;
}

glm::vec2 LineCollider::getPosition() {
    return (lineStart + lineEnd) / 2.0f;
}

float LineCollider::distanceToCollider(glm::vec2 position) {
    glm::vec2 closestPoint = glm::closestPointOnLine(position, lineStart, lineEnd);
    return glm::distance(closestPoint, position);
}

float LineCollider::getRadius() {
    return 0.01;
}

void LineCollider::addColliderForce(glm::vec2 forceVector) {}

bool LineCollider::isColliding(Collider *collider, glm::vec2& outVector) {
    glm::vec2 jointPosition = collider->getPosition();
    glm::vec2 closestPoint = glm::closestPointOnLine(jointPosition, lineStart, lineEnd);
    float jointRadius = collider->getRadius();
    float distanceToCollider = glm::distance(jointPosition, closestPoint);

    if ((distanceToCollider - getRadius()) < jointRadius){
        glm::vec2 forceVector = jointPosition - closestPoint;
        glm::normalize(forceVector);
        forceVector *= (jointRadius - (distanceToCollider - getRadius())) * 1.0f;
        outVector = forceVector;
        collider->addColliderForce(forceVector);
        return true;
    }
    return false;
}


void LineCollider::render() {
    drawTheLine(lineStart, lineEnd);
}
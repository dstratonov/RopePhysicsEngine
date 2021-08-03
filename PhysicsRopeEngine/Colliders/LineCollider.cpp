
#include "LineCollider.h"


LineCollider::LineCollider(glm::vec2 lineStart, glm::vec2 lineEnd) {
    a = lineStart.y - lineEnd.y;
    b = lineEnd.x - lineEnd.y;
    c = -a * lineStart.x - b * lineStart.y;
    this->lineStart = lineStart;
    this->lineEnd = lineEnd;
}

void LineCollider::collision(Joint* joint) {
    glm::vec2 jointPosition = joint->getPosition();
    float jointRadius = joint->getRadius();
    glm::vec2 closestPoint = glm::closestPointOnLine(jointPosition, lineStart, lineEnd);
    float distanceToCollider = glm::distance(jointPosition, closestPoint);

    if (distanceToCollider < jointRadius){
        glm::vec2 forceVector = jointPosition - closestPoint;
        glm::normalize(forceVector);
        forceVector *= (jointRadius - distanceToCollider) * 1.0f;
        joint->addColliderForce(forceVector);
    }
}

void LineCollider::render() {
    drawTheLine(lineStart, lineEnd);
}
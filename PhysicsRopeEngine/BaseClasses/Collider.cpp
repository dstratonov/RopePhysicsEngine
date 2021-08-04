//
// Created by strat on 8/3/2021.
//

#include "Collider.h"


void Collider::collision(Collider *collider) {
    glm::vec2 forceVector;
    if (isColliding(collider,forceVector)){
        collider->addColliderForce(forceVector);
        addColliderForce(-forceVector);
    }
}

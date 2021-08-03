//
// Created by strat on 8/3/2021.
//

#include "Collider.h"


void Collider::collision(Collider *joint) {
    glm::vec2 forceVector;
    if (isColliding(joint,forceVector)){
        joint->addColliderForce(forceVector);
    }
}

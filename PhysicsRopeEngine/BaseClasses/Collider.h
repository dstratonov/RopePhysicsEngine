#pragma once
#include "glm/ext.hpp"
#include "../Physics/Joint.h"
class Collider {
public:
    virtual void collision(Joint* joint) = 0;
};


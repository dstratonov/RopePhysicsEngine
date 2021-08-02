#pragma once
#include "../Scene/Scene.h"

class Scene;

class UpdatedObject {
public:
    explicit UpdatedObject(Scene* scene);

    virtual void update() = 0;
};




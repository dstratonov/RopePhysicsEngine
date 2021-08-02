#pragma once
#include "../Scene/Scene.h"

class Scene;

class RenderedObject{
public:
    RenderedObject(Scene* scene);
    virtual void render() = 0;
};
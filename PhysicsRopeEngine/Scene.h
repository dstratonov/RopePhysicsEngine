#pragma once
#include <vector>
#include "RenderedObject.h"
#include "UpdatedObject.h"

class UpdatedObject;
class RenderedObject;

class Scene {
public:
    void addRenderedObject(RenderedObject *object);

    void addUpdatedObject(UpdatedObject *object);

    void update();

private:
    std::vector<RenderedObject *> mRenderedObjects;
    std::vector<UpdatedObject *> mUpdatedObjects;
};

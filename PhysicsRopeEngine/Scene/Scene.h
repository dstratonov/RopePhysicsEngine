#pragma once
#include <vector>
#include "../BaseClasses/RenderedObject.h"
#include "../BaseClasses/UpdatedObject.h"
#include "../Utilities/DrawPrimitives.h"

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

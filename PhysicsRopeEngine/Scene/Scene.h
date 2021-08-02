#pragma once
#include <vector>
#include "../BaseClasses/RenderedObject.h"
#include "../BaseClasses/UpdatedObject.h"
#include "../Utilities/DrawPrimitives.h"
#include "../Physics/Joint.h"

class UpdatedObject;
class RenderedObject;

class Scene {
public:
    static Scene& getInstance(){

        static Scene sceneInstance;

        return sceneInstance;
    }

    Joint* createNewJoint(glm::vec2 initialPosition);
    Joint* createNewJoint(glm::vec2 initialPosition, float mass);

    void addRenderedObject(RenderedObject *object);

    void addUpdatedObject(UpdatedObject *object);

    ~Scene();

    void update();

private:
    std::vector<RenderedObject *> mRenderedObjects;
    std::vector<UpdatedObject *> mUpdatedObjects;
    std::vector<Joint*> mJoints;

    static Scene* sceneInstance;
};

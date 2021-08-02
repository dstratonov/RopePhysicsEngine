#include "Scene.h"



void Scene::addRenderedObject(RenderedObject *object){
    mRenderedObjects.push_back(object);
}

void Scene::addUpdatedObject(UpdatedObject *object) {
    mUpdatedObjects.push_back(object);
}

Joint* Scene::createNewJoint(glm::vec2 initialPosition){
    Joint* newJoint = new Joint(initialPosition);
    mJoints.push_back(newJoint);
    mUpdatedObjects.push_back(newJoint);
    mRenderedObjects.push_back(newJoint);
    return newJoint;
}

Joint* Scene::createNewJoint(glm::vec2 initialPosition, float mass){
    Joint* newJoint = new Joint(initialPosition, mass);
    mJoints.push_back(newJoint);
    mUpdatedObjects.push_back(newJoint);
    mRenderedObjects.push_back(newJoint);
    return newJoint;
}

Scene::~Scene(){
    for (int i = 0; i < mJoints.size(); i++){
        delete mJoints[i];
    }
    mJoints.clear();
    mUpdatedObjects.clear();
    mRenderedObjects.clear();
}

void Scene::update() {
    for (auto i : mUpdatedObjects){
        i->update();
    }
    for (auto i : mRenderedObjects){
        i->render();
    }

    drawTheLine(glm::vec2(-10, -2), glm::vec2(10, -2));

}
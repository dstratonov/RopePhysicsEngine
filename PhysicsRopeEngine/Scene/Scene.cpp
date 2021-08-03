#include "Scene.h"

Scene& Scene::getInstance(){
    static Scene sceneInstance;

    return sceneInstance;
}

void Scene::addJoint(Joint *joint) {
    mJoints.push_back(joint);
    addRenderedObject(joint);
    addUpdatedObject(joint);
}

void Scene::addRenderedObject(RenderedObject *object){
    mRenderedObjects.push_back(object);
}

void Scene::addUpdatedObject(UpdatedObject *object) {
    mUpdatedObjects.push_back(object);
}

Joint* Scene::createNewJoint(glm::vec2 initialPosition){
    Scene& scene = Scene::getInstance();
    Joint* newJoint = new Joint(initialPosition);
    scene.addJoint(newJoint);
    return newJoint;
}

Joint* Scene::createNewJoint(glm::vec2 initialPosition, float mass){
    Scene& scene = Scene::getInstance();
    Joint* newJoint = new Joint(initialPosition, mass);
    scene.addJoint(newJoint);
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

void Scene::updateObjects() {
    for (auto i : mUpdatedObjects){
        i->update();
    }
}

void Scene::renderObjects() {
    for (auto i : mRenderedObjects){
        i->render();
    }

    drawTheLine(glm::vec2(-10, -2), glm::vec2(10, -2));
}

void Scene::update() {
    Scene& scene = Scene::getInstance();
    scene.updateObjects();
    scene.renderObjects();
}
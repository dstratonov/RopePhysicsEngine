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

LineCollider* Scene::createNewLineCollider(glm::vec2 lineStart, glm::vec2 lineEnd) {
    Scene& scene = Scene::getInstance();
    auto* newCollider = new LineCollider(lineStart, lineEnd);
    scene.addRenderedObject(newCollider);
    scene.mColliders.push_back(newCollider);

    return newCollider;
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

    for (int i = 0; i < mColliders.size(); i++){
        delete mColliders[i];
    }

    mJoints.clear();
    mColliders.clear();
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
}

void Scene::update() {
    Scene& scene = Scene::getInstance();
    for (auto i : scene.mColliders){
        for (auto j : scene.mJoints){
            i->collision(j);
        }
    }
    scene.updateObjects();
    scene.renderObjects();
}
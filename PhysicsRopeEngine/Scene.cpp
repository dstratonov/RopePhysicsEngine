#include "Scene.h"


void Scene::addRenderedObject(RenderedObject *object){
    mRenderedObjects.push_back(object);
}

void Scene::addUpdatedObject(UpdatedObject *object) {
    mUpdatedObjects.push_back(object);
}

void Scene::update() {
    for (auto i : mUpdatedObjects){
        i->update();
    }
    for (auto i : mRenderedObjects){
        i->render();
    }
}
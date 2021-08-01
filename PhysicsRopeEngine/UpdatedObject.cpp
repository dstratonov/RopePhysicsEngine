#include "UpdatedObject.h"


UpdatedObject::UpdatedObject(Scene *scene) {
        scene->addUpdatedObject(this);
}
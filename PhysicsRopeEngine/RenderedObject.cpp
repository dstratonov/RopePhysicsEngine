#include "RenderedObject.h"


RenderedObject::RenderedObject(Scene *scene) {
    scene->addRenderedObject(this);
}
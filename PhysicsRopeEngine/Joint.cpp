#include "Joint.h"
#include "DrawPrimitives.h"

void Joint::update() {
    mVelocity = mVelocity + (GRAVITY * PHYSIC_STEP) / mMass;
    mPosition = mPosition + mVelocity;
    reDraw();
}

void Joint::reDraw() {
    Primitives::drawTheCircle(mPosition, DEFAULT_JOINT_RADIUS);
}
cmake_minimum_required(VERSION 3.19)
project(PhysicsRopeEngine)

set(CMAKE_CXX_STANDARD 14)


add_executable(PhysicsRopeEngine main.cpp Physics/Joint.h Utilities/DrawPrimitives.h Physics/Joint.cpp Utilities/DrawPrimitives.cpp Scene/Scene.cpp Scene/Scene.h BaseClasses/RenderedObject.cpp BaseClasses/RenderedObject.h BaseClasses/UpdatedObject.cpp BaseClasses/UpdatedObject.h)

target_link_libraries(PhysicsRopeEngine -lOpenGl32 -lfreeGLUT -lglfw3)



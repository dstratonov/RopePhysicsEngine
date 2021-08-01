cmake_minimum_required(VERSION 3.19)
project(PhysicsRopeEngine)

set(CMAKE_CXX_STANDARD 14)


add_executable(PhysicsRopeEngine main.cpp Joint.h DrawPrimitives.h Joint.cpp DrawPrimitives.cpp)

target_link_libraries(PhysicsRopeEngine -lOpenGl32 -lfreeGLUT -lglfw3)



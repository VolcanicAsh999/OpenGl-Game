#pragma once

#include "vec3.h"
#include "line.h"
#include "OpenGL.h"
#include "cube.h"

class Triangle {
public:
    vector<Vec3> pos;
    int r, g, b;
    float base;
    float height;
    float depth;
    Triangle(float mx, float my, float mz, float mbase, float mheight, float mdepth, bool mflipped);
    bool collided(float px, float py, float pz);
    bool collidex(float px);
    bool collidey(float py);
    bool collidez(float pz);
    void render();
    float x, y, z;
    Cube cube1;
    Cube cube2;
    bool flipped;
};

#pragma once
#include "OpenGL.h"

class Cube {
public:
    int x, y, z;
    int width, height, depth;
    Cube(int mx, int my, int mz, int mwidth, int mheight, int mdepth);
    Cube(int mx, int my, int mz, int mwidth, int mheight, int mdepth, int mr, int mg, int mb);
    Cube();
    bool collided(float px, float py, float pz);
    bool collidex(float px);
    bool collidey(float py);
    bool collidez(float pz);
    void render();
    void setColor(int mr, int mg, int mb);
    int w, h, d;
    int r, g, b;
};

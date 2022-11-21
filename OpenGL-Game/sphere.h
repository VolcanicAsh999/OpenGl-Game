#include "OpenGL.h"

class Sphere {
public:
    Sphere(int mx, int my, int mz, int mradius);
    Sphere(int mx, int my, int mz, int mradius, int mr, int mg, int mb);
    void render();
    bool collided(float px, float py, float pz);
    bool collidex(float px);
    bool collidey(float py);
    bool collidez(float pz);
    int x, y, z;
    int radius;
    int r, g, b;
    void setColor(int mr, int mg, int mb);
};

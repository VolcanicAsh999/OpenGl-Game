#pragma once
#include "OpenGL.h"
#include "cube.h"
#include "rng.h"

class Room {
public:
    void render();
    bool collided(float px, float py, float pz);
    bool collidex(float px);
    bool collidey(float py);
    bool collidez(float pz);
    Room(char* mname);
    Room();
    char* name;
    vector<Cube> cubes;
};

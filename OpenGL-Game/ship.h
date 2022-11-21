#pragma once
#include "OpenGL.h"
#include "cube.h"
#include "rng.h"
#include "room.h"

class Ship {
public:
    int midx, midy, midz;
    Ship();
    void render();
    int ROOMSCOUNT = 0;
    Room rooms[];
};

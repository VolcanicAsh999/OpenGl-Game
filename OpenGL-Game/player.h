#pragma once
#include "OpenGL.h"

class Player {
public:
    int health;
    Player(int startHealth);
    void addHealth(int changeHealth);
    int x, y, z;
};

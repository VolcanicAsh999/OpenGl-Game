#pragma once
#include "OpenGL.h"
#include "cube.h"

class Rand {
public:
    int seed;
    int randint();
    int randrange(int mmax);
    int randint(int mmin, int mmax);
    Rand(int mseed);
    Rand();
};

int genRandNum(int min, int max);
int randrange(int max);

void initRand();

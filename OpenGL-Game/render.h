#pragma once
#include "OpenGL.h"
#include "cube.h"
#include "keybinds.h"
#include "rng.h"

void initD();
void initCubes();
void renderCubes();

void renderSpheres();
void initSpheres();

bool playerIsTouching(float x, float y, float z);
bool collidex(float x);
bool collidey(float y);
bool collidez(float z);

//Cube genRandCube();

void render(void);

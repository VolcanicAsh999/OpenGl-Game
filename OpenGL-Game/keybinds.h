#ifndef _KEYS_H_
#define _KEYS_H_

#include "OpenGL.h"
#include "render.h"

void mouseMove(int x, int y);
void mousePress(int button, int state, int x, int y);
void initKeys();
void updatePosDir();
void fixPosDir();
void pressKey(unsigned char key, int xx, int yy);
void releaseKey(unsigned char key, int xx, int yy);
void translateRight();

#endif // _KEYS_H_

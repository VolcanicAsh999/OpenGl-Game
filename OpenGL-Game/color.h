#ifndef _COLOR_H_
#define _COLOR_H_

#include "OpenGL.h" // just an easier way to include gl.h and vector

class Color {
public:
    Color(int mr, int mg, int mb);
    int r, g, b;
    void setColor();
    Color();
};

//Color RED, GREEN, BLUE, YELLOW, PURPLE, CYAN, BLACK, WHITE;

vector<Color> allColors;

Color getColorByName(char* name);

void initColors();

#endif

#include "color.h"
#include "OpenGL.h"

Color::Color(int mr, int mg, int mb)
    :r(mr), g(mg), b(mb)
{

}

Color::Color()
    :r(0), g(0), b(0)
{

}

void Color::setColor()
{
    glColor3ub(r, g, b);
}

void initColors()
{
    Color RED = Color(255, 0, 0);
    Color GREEN = Color(0, 255, 0);
    Color BLUE = Color(0, 0, 255);
    Color PURPLE = Color(255, 0, 255);
    Color YELLOW = Color(255, 255, 0);
    Color CYAN = Color(0, 255, 255);
    Color BLACK = Color(0, 0, 0);
    Color WHITE = Color(255, 255, 255);

    allColors.push_back(RED);
    allColors.push_back(GREEN);
    allColors.push_back(BLUE);
    allColors.push_back(PURPLE);
    allColors.push_back(YELLOW);
    allColors.push_back(CYAN);
    allColors.push_back(BLACK);
    allColors.push_back(WHITE);
}

Color getColorByName(char* name)
{
    if (name == "red")
        return allColors[0];
    if (name == "green")
        return allColors[1];
    if (name == "blue")
        return allColors[2];
    if (name == "purple")
        return allColors[3];
    if (name == "yellow")
        return allColors[4];
    if (name == "cyan")
        return allColors[5];
    if (name == "black")
        return allColors[6];
    if (name == "white")
        return allColors[7];
    return allColors[7]; // If color is invalid, just return white
}

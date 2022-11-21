#include "OpenGL.h"
#include "cube.h"

Cube::Cube(int mx, int my, int mz, int mwidth, int mheight, int mdepth)
    :x(mx), y(my), z(mz), width(mwidth), height(mheight), depth(mdepth), w(mwidth), h(mheight), d(mdepth)
{

}

Cube::Cube(int mx, int my, int mz, int mwidth, int mheight, int mdepth, int mr, int mg, int mb)
    :x(mx), y(my), z(mz), width(mwidth), height(mheight), depth(mdepth), w(mwidth), h(mheight), d(mdepth), r(mr), g(mg), b(mb)
{

}

Cube::Cube()
{

}

void Cube::render()
{
    glColor3ub(r, g, b);

    // FRONT
    glBegin(GL_POLYGON);
        glVertex3f(x - w, y - h, z - d);
        glVertex3f(x - w, y + h, z - d);
        glVertex3f(x + w, y + h, z - d);
        glVertex3f(x + w, y - h, z - d);
    glEnd();

    // BACK
    glBegin(GL_POLYGON);
        glVertex3f(x + w, y - h, z + d);
        glVertex3f(x + w, y + h, z + d);
        glVertex3f(x - w, y + h, z + d);
        glVertex3f(x - w, y - h, z + d);
    glEnd();

    // RIGHT
    glBegin(GL_POLYGON);
        glVertex3f(x + w, y - h, z - d);
        glVertex3f(x + w, y + h, z - d);
        glVertex3f(x + w, y + h, z + d);
        glVertex3f(x + w, y - h, z + d);
    glEnd();

    // LEFT
    glBegin(GL_POLYGON);
        glVertex3f(x - w, y - h, z + d);
        glVertex3f(x - w, y + h, z + d);
        glVertex3f(x - w, y + h, z - d);
        glVertex3f(x - w, y - h, z - d);
    glEnd();

    // TOP
    glBegin(GL_POLYGON);
        glVertex3f(x + w, y + h, z + d);
        glVertex3f(x + w, y + h, z - d);
        glVertex3f(x - w, y + h, z - d);
        glVertex3f(x - w, y + h, z + d);
    glEnd();

    // BOTTOM
    glBegin(GL_POLYGON);
        glVertex3f(x + w, y - h, z - d);
        glVertex3f(x + w, y - h, z + d);
        glVertex3f(x - w, y - h, z + d);
        glVertex3f(x - w, y - h, z - d);
    glEnd();
}

void Cube::setColor(int mr, int mg, int mb)
{
    r = mr;
    g = mg;
    b = mb;
}

bool Cube::collided(float px, float py, float pz)
{
    if (collidex(px) && collidey(py) && collidez(pz))
    {
        return true;
    }
    return false;
}

bool Cube::collidex(float px)
{
    if ((x - w - 1.3 < px) && (px < x + w + 1.3))
        return true;
    return false;
}

bool Cube::collidey(float py)
{
    if ((y - h - 1 < py) && (py < y + h + 1)) {
        return true;
    }
    return false;
}

bool Cube::collidez(float pz)
{
    if ((z - d - 1.3 < pz) && (pz < z + d + 1.3)) {
        return true;
    }
    return false;
}

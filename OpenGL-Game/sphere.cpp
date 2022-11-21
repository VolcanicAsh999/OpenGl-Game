#include "OpenGL.h"
#include "sphere.h"

Sphere::Sphere(int mx, int my, int mz, int mradius)
    :x(mx), y(my), z(mz), radius(mradius)
{

}

Sphere::Sphere(int mx, int my, int mz, int mradius, int mr, int mg, int mb)
    :x(mx), y(my), z(mz), radius(mradius), r(mr), g(mg), b(mb)
{

}

void Sphere::render()
{
    glColor3ub(r, g, b);
    glTranslatef(x-radius, y, z-radius); // So the collision detection box and drawing box overlap completely
    glutSolidSphere(radius-2, 20, 20); // Because the radius of the sphere is a little bigger than what you tell it to do
}

bool Sphere::collided(float px, float py, float pz)
{
    if (sqrt((px-x+radius)*(px-x+radius) + (py-y)*(py-y) + (pz-z+radius)*(pz-z+radius)) < radius) {
        return true;
    }
    return false;
}

bool Sphere::collidex(float px)
{
    return false; // No good way to tell, not used anyway (yet)
}

bool Sphere::collidey(float py)
{
    return false; // No good way to tell, not used anyway (yet)
}

bool Sphere::collidez(float pz)
{
    return false; // No good way to tell, not used anyway (yet)
}

void Sphere::setColor(int mr, int mg, int mb)
{
    r = mr;
    g = mg;
    b = mb;
}

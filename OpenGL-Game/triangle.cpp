#include "line.h"
#include "vec3.h"
#include "OpenGL.h"
#include "triangle.h"
#include "cube.h"

float ypad = 1;
float xpad = 2;
float zpad = 2;

Triangle::Triangle(float mx, float my, float mz, float mbase, float mheight, float mdepth, bool mflipped)
    :base(mbase), depth(mdepth), height(mheight), x(mx), y(my), z(mz), flipped(mflipped)
{
    if (mflipped)
    {
        pos.push_back(Vec3(mx, my, mz));
        pos.push_back(Vec3(mx, my, mz + base));
        pos.push_back(Vec3(mx, my + height, mz + base));
        pos.push_back(Vec3(mx + depth, my, mz));
        pos.push_back(Vec3(mx + depth, my, mz + base));
        pos.push_back(Vec3(mx + depth, my + height, mz + base));
        cube1 = Cube((mx+depth)/2, my, (mz+base)/2, depth/2, .2, base/2);
        cube2 = Cube(mx+depth, (my+height)/2, (mz+base)/2, .25, height/2, (base/2));
    }
    else
    {
        pos.push_back(Vec3(mx, my, mz));
        pos.push_back(Vec3(mx + base, my, mz));
        pos.push_back(Vec3(mx + base, my + height, mz));
        pos.push_back(Vec3(mx, my, mz + depth));
        pos.push_back(Vec3(mx + base, my, mz + depth));
        pos.push_back(Vec3(mx + base, my + height, mz + depth));
        cube1 = Cube((mx+base)/2, my, (mz+depth)/2, base/2, .2, depth/2);
        cube2 = Cube(mx+base, (my+height)/2, (mz+depth)/2, .25, height/2, (depth/2));
    }
}

bool Triangle::collided(float px, float py, float pz)
{
    //if ((px - xpad < pos.x && pos.x < px + xpad) && (py - ypad < pos.y && pos.y < py + ypad) && (pz - zpad < pos.z && pos.z < pz + zpad))
    //    return true;

    for (auto vec = pos.begin(); vec != pos.end(); ++vec)
    {
        if ((px - xpad < vec->x && vec->x < px + xpad) && (py - ypad < vec->y && vec->y < py + ypad) && (pz - zpad < vec->z && vec->z < pz + zpad))
            return true;
    }
    /*if (pointOnLine(pos[0], pos[1], Vec3(px, py, pz), Vec3(1.3, 1, 1.3)))
        return true;
    if (pointOnLine(pos[3], pos[4], Vec3(px, py, pz), Vec3(1.3, 1, 1.3)))
        return true;*/
    if (cube1.collided(px, py, pz) || cube2.collided(px, py, pz))
        return true;
    return false;
}

void Triangle::render()
{
    glColor3ub(r, g, b);

    if (!flipped)
    {
        glBegin(GL_TRIANGLES);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
        glEnd();
    }
    else
    {
        glBegin(GL_TRIANGLES);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
            glVertex3f(pos[3].x, pos[3].y, pos[3].z);
            glVertex3f(pos[0].x, pos[0].y, pos[0].z);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(pos[2].x, pos[2].y, pos[2].z);
            glVertex3f(pos[1].x, pos[1].y, pos[1].z);
            glVertex3f(pos[4].x, pos[4].y, pos[4].z);
            glVertex3f(pos[5].x, pos[5].y, pos[5].z);
        glEnd();
    }
}

bool Triangle::collidex(float px) {
    if(!flipped) {
            for (auto vec = pos.begin(); vec != pos.end(); ++vec) {
                if (px - xpad < vec->x && vec->x < px + xpad)
                    return true;
            }
    }
    return false;
}

bool Triangle::collidey(float py) {
    if(!flipped) {
        for (auto vec = pos.begin(); vec != pos.end(); ++vec) {
            if (py - ypad < vec->y && vec->y < py + ypad)
                return true;
        }
    }
    return false;
}

bool Triangle::collidez(float pz) {
    if(!flipped) {
        for (auto vec = pos.begin(); vec != pos.end(); ++vec) {
            if (pz - zpad < vec->z && vec->z < pz + zpad)
                return true;
        }
    }
    return false;
}

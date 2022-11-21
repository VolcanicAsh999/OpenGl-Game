#include "OpenGL.h"
#include "cube.h"
#include "rng.h"
#include "keybinds.h"
#include "sphere.h"
#include "player.h"
#include "triangle.h"

Cube ground = Cube(0, 0, 0, 500, 1, 500, 255, 255, 255);

vector<Cube> cubes;
vector<Sphere> spheres;
vector<Triangle> triangles;

#define MAXX 500
#define MINX -500
#define MAXZ 500
#define MINZ -500
#define MAXY 5
#define MINY 3
#define MAXW 6
#define MINW 1
#define MAXD 6
#define MIND 1
#define MAXH 5
#define MINH 3
#define MINR 4
#define MAXR 10
#define MINCUBES 80
#define MAXCUBES 150
#define MINSPHERES 10
#define MAXSPHERES 20
int CUBESLENGTH = genRandNum(MINCUBES, MAXCUBES);
int SPHERESLENGTH = genRandNum(MINSPHERES, MAXSPHERES);

Cube genRandCube()
{
    int x = genRandNum(MINX, MAXX);
    int y = genRandNum(MINY, MAXY);
    int z = genRandNum(MINZ, MAXZ);
    int width = genRandNum(MINW, MAXW);
    int height = genRandNum(MINH, MAXH);
    int depth = genRandNum(MIND, MAXD);
    //int r = genRandNum(0, 255);
    //int g = genRandNum(0, 255);
    //int b = genRandNum(0, 255);
    Cube cube = Cube(x, y, z, width, height, depth);
    return cube;
}

Sphere genRandSphere()
{
    int x = genRandNum(MINX, MAXX);
    int y = genRandNum(MINY, MAXY);
    int z = genRandNum(MINZ, MAXZ);
    int radius = genRandNum(MINR, MAXR);
    Sphere sphere = Sphere(x, y, z, radius);
    return sphere;
}

void initCubes()
{
    //othercubes[0] = Cube(5, 2, 5, 3, 3, 3, 0, 256, 0);
    //othercubes[1] = Cube(-5, 2, 10, 3, 2, 6, 256, 0, 0);
    for (int i = 0; i < CUBESLENGTH; i++)
    {
        Cube cube = genRandCube();
        int j = randrange(7);
        if (j == 0)
            cube.setColor(255, 0, 0);
        else if (j == 1)
            cube.setColor(0, 255, 0);
        else if (j == 2)
            cube.setColor(0, 0, 255);
        else if (j == 3)
            cube.setColor(255, 255, 0);
        else if (j == 4)
            cube.setColor(0, 255, 255);
        else if (j == 5)
            cube.setColor(255, 0, 255);
        else if (j == 6)
            cube.setColor(255, 255, 255);
        else if (j == 7)
            cube.setColor(0, 0, 0);
        else
        {
            cout << "Error - invalid color choice " << j << ", how did that happen?";
            cube.setColor(128, 128, 128);
        }
        cubes.push_back(cube);
    }
    //othercubes[0] = Cube(0, 1, 0, 2, 1, 2, 255, 0, 0);
}

void initSpheres()
{
    /*for (int i = 0; i < SPHERESLENGTH; i++)
    {
        Sphere sphere = genRandSphere();
        int j = randrange(7);
        if (j == 0)
            sphere.setColor(255, 0, 0);
        else if (j == 1)
            sphere.setColor(0, 255, 0);
        else if (j == 2)
            sphere.setColor(0, 0, 255);
        else if (j == 3)
            sphere.setColor(255, 255, 0);
        else if (j == 4)
            sphere.setColor(0, 255, 255);
        else if (j == 5)
            sphere.setColor(255, 0, 255);
        else if (j == 6)
            sphere.setColor(255, 255, 255);
        else if (j == 7)
            sphere.setColor(0, 0, 0);
        else
        {
            cout << "Error - invalid color choice " << j << ", how did that happen?";
            sphere.setColor(128, 128, 128);
        }
        spheres.push_back(sphere);
    }*/
    spheres.push_back(Sphere(20, 5, 20, 10, 255, 0, 0));
}

void initTriangles()
{
    triangles.push_back(Triangle(-5, 2, -5, 5, 5, 3, false));
    triangles[0].r = 255;
    triangles[0].g = 0;
    triangles[0].b = 0;
    triangles.push_back(Triangle(20, 3, 10, 7, 4, 5, true));
    triangles[1].r = 0;
    triangles[1].g = 255;
    triangles[1].b = 0;
}

void renderCubes()
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        cube->render();
    }
} // For random cubes

void renderSpheres()
{
    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere)
    {
        sphere->render();
    }
}

void renderTriangles()
{
    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle)
    {
        triangle->render();
    }
}

/*Ship ships[] = {};

int CUBESLENGTH = 0;
int SHIPSLENGTH = 0;

void initCubes()
{
    ships[0] = Ship();
    SHIPSLENGTH = 1;
}

void renderCubes()
{
    for (int i = 0; i < SHIPSLENGTH; i++)
    {
        ships[i].render();
    }
}*/ // For ships

/*void initCubes()
{
    othercubes[0] = getRoom("MainRoom");
    CUBESLENGTH = 1
}

void renderCubes()
{
    for (i = 0; i < CUBESLENGTH; i++)
        othercubes[i].render();
}*/ // For rooms

/*int index = 0;
int CUBESLENGTH = 0;

void renderMainRoom()
{
    cubes[index].render();
    cubes[index + 1].render();
    cubes[index + 2].render();
    cubes[index + 3].render();
    cubes[index + 4].render();
}

void renderShip()
{
    renderMainRoom();
}

void createMainRoom(float x, float y, float z)
{
    cubes[index] = Cube(10 + x, 5 + y, 0 + z, .5, 5, 5, 20, 20, 20);
    cubes[index + 1] = Cube(-10 + x, 5 + y, 0 + z, .5, 5, 5, 20, 20, 20);
    cubes[index + 2] = Cube(0 + x, 5 + y, 10 + z, 5, 5, .5, 20, 20, 20);
    cubes[index + 3] = Cube(-3 + x, 5 + y, -10 + z, 2, 5, .5, 20, 20, 20);
    cubes[index + 4] = Cube(3 + x, 5 + y, -10 + z, 2, 5, .5, 20, 20, 20);
    for (int i = 0; i < 5; i++)
        cubes[index + i].setColor(20, 20, 20);
    CUBESLENGTH += 5;
}

void createShip(float x, float y, float z)
{
    createMainRoom(x, y, z);
}

void initCubes()
{
    createShip(0, 0, 0);
}

void renderCubes()
{
    renderShip();
}*/ // For Ship-Rooms...

void initD()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    initCubes();
    initSpheres();
    initTriangles();
}

void render(void) {
    // Set the camera

    //glViewport(0, 0, 640, 480);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    updatePosDir();

    fixPosDir();

    ground.render();

    renderCubes();

    renderTriangles();

    renderSpheres();
    translateRight();

    //renderTriangles();

    glutSwapBuffers();
}

bool playerIsTouching(float x, float y, float z)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if (cube->collided(x, y, z)) {
            return true;
        }
    }
    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere)
    {
        if (sphere->collided(x, y, z)) {
            return true;
        }
    }
    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle)
    {
        if (triangle->collided(x, y, z)) {
            return true;
        }
    }
    /*for (int i = 0; i < CUBESLENGTH; i++) {
        if
    }*/
    if (ground.collided(x, y, z)) {
        return true;
    }
    return false;
}

bool collidex(float x)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if (cube->collidex(x))
            return true;
    }
    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere)
    {
        if (sphere->collidex(x)) {
            return true;
        }
    }
    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle)
    {
        if (triangle->collidex(x)) {
            return true;
        }
    }
    if (ground.collidex(x))
        return true;
    return false;
}

bool collidey(float y)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if (cube->collidey(y))
            return true;
    }
    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere)
    {
        if (sphere->collidey(y)) {
            return true;
        }
    }
    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle)
    {
        if (triangle->collidey(y)) {
            return true;
        }
    }
    if (ground.collidey(y))
        return true;
    return false;
}

bool collidez(float z)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if (cube->collidez(z))
            return true;
    }
    for (auto sphere = spheres.begin(); sphere != spheres.end(); ++sphere)
    {
        if (sphere->collidez(z)) {
            return true;
        }
    }
    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle)
    {
        if (triangle->collidez(z)) {
            return true;
        }
    }
    if (ground.collidez(z))
        return true;
    return false;
}

#include "render.h"

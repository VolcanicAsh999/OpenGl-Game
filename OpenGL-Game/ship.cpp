#include "OpenGL.h"
#include "cube.h"
#include "rng.h"
#include "room.h"
#include "ship.h"

Ship::Ship()
{
    rooms[0] = Room(MAINROOM);
    ROOMSCOUNT = 1;
}

void Ship::render()
{
    for (int i = 0; i < ROOMSCOUNT; i++)
        rooms[i].render();
}

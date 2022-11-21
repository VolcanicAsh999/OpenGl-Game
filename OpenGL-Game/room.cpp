#include "OpenGL.h"
#include "room.h"
#include "cube.h"
#include "rng.h"

Room::Room(char* mname)
    :name(mname)
{

}

Room::Room()
{

}

void Room::render()
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        (*cube).render();
    }
}

bool Room::collided(float px, float py, float pz)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if ((*cube).collided(px, py, pz))
            return true;
    }
    return false;
}

bool Room::collidex(float px)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if ((*cube).collidex(px))
            return true;
    }
    return false;
}

bool Room::collidey(float py)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if ((*cube).collidey(py))
            return true;
    }
    return false;
}

bool Room::collidez(float pz)
{
    for (auto cube = cubes.begin(); cube != cubes.end(); ++cube)
    {
        if ((*cube).collidez(pz))
            return true;
    }
    return false;
}

Room mainRoom; // rooms are here

bool initRooms() {
    mainRoom = Room("MainRoom");
    //mainRoom.cubes.push_back;
    return 1;
}

Room getRoom(char* name) {
    if (name == "MainRoom")
        return mainRoom;
    return NULL;
}

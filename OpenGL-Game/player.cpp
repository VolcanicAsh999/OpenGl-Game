#include "OpenGL.h"
#include "player.h"

Player::Player(int startHealth)
    :health(startHealth)
{

}

void Player::addHealth(int changeHealth)
{
    health += changeHealth;
    if (health > 20)
        health = 20;
    if (health < 0) {
        printf("You died!");
        health = 0;
    }
}

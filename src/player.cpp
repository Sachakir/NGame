#include "player.hpp"
#include <ostream>
#include <stdlib.h>     /* abs */
using namespace std;

Player::Player()
{
    Player::x = 42;
    Player::y = 200;
    Player::xSpeed = 0;
    Player::ySpeed = 0;
    Player::height = 65;
    Player::width = 30;
}

void Player::setX(int x)
{
    Player::x = x;
}

int Player::getX() const
{
    return Player::x;
}

void Player::setY(int y)
{
    Player::y = y;
}

int Player::getY() const
{
    return Player::y;
}

int Player::getHeight() const
{
    return Player::height;
}

int Player::getWidth() const
{
    return Player::width;
}

int Player::getXSpeed() const
{
    return xSpeed;
}

int Player::getYSpeed() const
{
    return ySpeed;
}

void Player::setXSpeed(int xSpeed)
{
    Player::xSpeed = xSpeed;
}

void Player::setYSpeed(int ySpeed)
{
    Player::ySpeed = ySpeed;
}
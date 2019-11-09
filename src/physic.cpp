#include "physic.hpp"
#include <iostream>
#include<algorithm>
#include "events.hpp"

using namespace std;

Physic::Physic(Room * room)
{
    Physic::room = room;
    Physic::g = 1000;
    Physic::maxSpeed = 500;
}

int Physic::verticalCollision(int deltaY)
{
    if (deltaY > 0)//Fall down, find a cube just under the player
    {
        vector<int> * groundLvl = new vector<int>();
        for (int i = 0;i < room->getBlocs()->size();i++)
        {
            if ((*room->getBlocs())[i]->getY() >= (room->getPlayer()->getY() + room->getPlayer()->getHeight()) )//cube is under
            {
                if ((room->getPlayer()->getY() + room->getPlayer()->getHeight() + deltaY) >= (*room->getBlocs())[i]->getY())//player will hit it
                {
                    if (room->getPlayer()->getX() <= ((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth()) &&
                       (room->getPlayer()->getX() + room->getPlayer()->getWidth()) >= ((*room->getBlocs())[i]->getX()) )//right X
                    {
                        groundLvl->push_back((*room->getBlocs())[i]->getY());
                    }
                }
            }
        }
        if (!groundLvl->empty())
        {
            int max = *max_element(groundLvl->begin(), groundLvl->end());
            return max;
        }
        else
        {
            return -1;
        }
        delete groundLvl;
    }
    else if (deltaY < 0)//Jump
    {
        vector<int> * ceilLvl = new vector<int>();
        for (int i = 0;i < room->getBlocs()->size();i++)
        {
            if ( ((*room->getBlocs())[i]->getY() + (*room->getBlocs())[i]->getHeight()) <= room->getPlayer()->getY() )//cube is above
            {
                if ((room->getPlayer()->getY() + deltaY) <= ((*room->getBlocs())[i]->getY() + (*room->getBlocs())[i]->getHeight()) )//player will hit it
                {
                    if (room->getPlayer()->getX() <= ((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth()) &&
                       (room->getPlayer()->getX() + room->getPlayer()->getWidth()) >= ((*room->getBlocs())[i]->getX()) )//right X
                    {
                        ceilLvl->push_back((*room->getBlocs())[i]->getY() + (*room->getBlocs())[i]->getHeight());
                    }
                }
            }
        }
        if (!ceilLvl->empty())
        {
            int max = *max_element(ceilLvl->begin(), ceilLvl->end());
            return max;
        }
        else
        {
            return -1;
        }
        delete ceilLvl;
    }
    return -1;
}

int Physic::horizontalCollision(int deltaX)
{
    if (deltaX > 0)//Goes right
    {
        vector<int> * rightSide = new vector<int>();
        for (int i = 0;i < room->getBlocs()->size();i++)
        {
            if ((*room->getBlocs())[i]->getX() >= (room->getPlayer()->getX() + room->getPlayer()->getWidth()) )//cube is under
            {
                if ((room->getPlayer()->getX() + room->getPlayer()->getWidth() + deltaX) >= (*room->getBlocs())[i]->getX())//player will hit it
                {
                    if (room->getPlayer()->getY() < ((*room->getBlocs())[i]->getY() + (*room->getBlocs())[i]->getHeight()) &&
                       (room->getPlayer()->getY() + room->getPlayer()->getHeight()) > ((*room->getBlocs())[i]->getY()) )//right Y
                    {
                        rightSide->push_back((*room->getBlocs())[i]->getX());
                    }
                }
            }
        }
        if (!rightSide->empty())
        {
            int max = *min_element(rightSide->begin(), rightSide->end());
            return max;
        }
        else
        {
            return -1;
        }
        delete rightSide;
    }
    else if (deltaX < 0)//Goes left
    {
        vector<int> * leftSide = new vector<int>();
        for (int i = 0;i < room->getBlocs()->size();i++)
        {
            if ( ((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth()) <= room->getPlayer()->getX() )
            {
                if ((room->getPlayer()->getX() + deltaX) <= ((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth()) )//player will hit it
                {
                    if (room->getPlayer()->getY() < ((*room->getBlocs())[i]->getY() + (*room->getBlocs())[i]->getHeight()) &&
                       (room->getPlayer()->getY() + room->getPlayer()->getHeight()) > ((*room->getBlocs())[i]->getY()) )//right y
                    {
                        leftSide->push_back((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth());
                    }
                }
            }
        }
        if (leftSide->size() > 0)
        {
            int max = *max_element(leftSide->begin(), leftSide->end());
            return max;
        }
        else
        {
            return -1;
        }
        delete leftSide;
    }
    return -1;
}

void Physic::moveUp()
{
    if (room->getStanding())
    {
        room->getPlayer()->setYSpeed(-2000);
    }
}

void Physic::moveLeft()
{
    room->getPlayer()->setXSpeed(-300);
}

void Physic::moveRight()
{
    room->getPlayer()->setXSpeed(300);
}

bool Physic::isStanding() const
{
    for (int i = 0;i < room->getBlocs()->size();i++)
    {
        if ((*(room->getBlocs()))[i]->getY() == (room->getPlayer()->getY() + room->getPlayer()->getHeight()))
        {
            if (room->getPlayer()->getX() <= ((*room->getBlocs())[i]->getX() + (*room->getBlocs())[i]->getWidth()) &&
                       (room->getPlayer()->getX() + room->getPlayer()->getWidth()) >= ((*room->getBlocs())[i]->getX()) )//right X
                    {
                        return true;
                    }
        }
    }
    return false;
}

void Physic::update(int ms)
{
    if (isStanding())
    {
        room->setStanding(true);
    }
    else
    {
        room->setStanding(false);
    }
    
    if (!room->getStanding())//Falling
    {
        room->getPlayer()->setYSpeed(min(
                                    (int)(room->getPlayer()->getYSpeed() + (g * ((double)ms / 1000))),
                                    maxSpeed
                                    )
                                );
    }
    
    int deltaX = room->getPlayer()->getXSpeed() * (double)ms /1000;
    room->getPlayer()->setXSpeed(room->getPlayer()->getXSpeed() * 0.7);
    int deltaY = room->getPlayer()->getYSpeed() * (double)ms /1000;
    int y;
    int x;
    x = horizontalCollision(deltaX);
    y = verticalCollision(deltaY);
    if (y == -1)
    {
        room->getPlayer()->setY(room->getPlayer()->getY() + deltaY);
    }
    else
    {
        room->getPlayer()->setYSpeed(0);
        if (deltaY > 0)
        {
            room->getPlayer()->setY(y-room->getPlayer()->getHeight());
        }
        else if (deltaY < 0)
        {
            room->getPlayer()->setY(y);
        }
    }
    if (x == -1)
    {
        room->getPlayer()->setX(room->getPlayer()->getX() + deltaX);
    }
    else
    {
        room->getPlayer()->setXSpeed(0);
        if (deltaX > 0)
        {
            room->getPlayer()->setX(x-room->getPlayer()->getWidth());
        }
        else if (deltaX < 0)
        {
            room->getPlayer()->setX(x);
        }
    }
    
    
    
}
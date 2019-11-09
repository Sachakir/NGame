#ifndef PHYSIC_H_INCLUDED
#define PHYSIC_H_INCLUDED

#include "room.hpp"

class Physic
{
    public:
        Physic(Room * room);
        void update(int ms); //Apply all physics
        void moveLeft();
        void moveRight();
        void moveUp();
        bool isStanding() const;
    private:
        int verticalCollision(int deltaY);
        int horizontalCollision(int deltaX);
        int maxSpeed;
        int g;
        Room * room;
};

#endif // PHYSIC_H_INCLUDED
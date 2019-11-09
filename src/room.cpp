#include "room.hpp"
#include <iostream>
using namespace std;

Room::Room()
{
    Room::player = new Player();
    otherPlayer = new Player();
    otherPlayerInGame = false;
    player->setX(500);
    standing = false;
    Bloc * bl0 = new Bloc(100,100,50,20);
    Bloc * bl1 = new Bloc(100,600,50,20);
    Bloc * bl2 = new Bloc(160,600,50,20);
    Bloc * sol = new Bloc(0,700,1200,20);
    Bloc * plafond = new Bloc(0,0,1200,20);
    Bloc * wallLeft = new Bloc(0,0,50,720);
    Bloc * wallRight = new Bloc(1150,0,50,720);
    Room::blocs = new vector<Bloc *>();
    Room::blocs->push_back(bl0);
    blocs->push_back(bl1);
    blocs->push_back(bl2);
    Room::blocs->push_back(sol);
    Room::blocs->push_back(plafond);
    blocs->push_back(wallLeft);
    blocs->push_back(wallRight);
    Room::width = 1200;
    Room::height = 720;
}

Room::~Room()
{
    for (int i = 0;i < blocs->size();i++)
    {
        delete (*blocs)[i];
    }
    delete blocs;
    delete player;
}

Player * Room::getPlayer()
{
    return player;
}

Player * Room::getOtherPlayer()
{
    return otherPlayer;
}

vector<Bloc*> * Room::getBlocs()
{
    return blocs;
}

int Room::getWidth() const
{
    return Room::width;
}

int Room::getHeight() const
{
    return Room::height;
}

bool Room::getStanding() const
{
    return standing;
}

void Room::setStanding(bool standing)
{
    Room::standing = standing;
}
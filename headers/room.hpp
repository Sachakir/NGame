#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "player.hpp"
#include "bloc.hpp"
#include <vector>

class Room
{
    public:
        Room();
        ~Room();
        Player * getPlayer();
        Player * getOtherPlayer();
        std::vector<Bloc*> * getBlocs();
        int getWidth() const;
        int getHeight() const;
        bool getStanding() const;
        void setStanding(bool standing);
    private:
        Player * player;
        Player * otherPlayer;
        bool otherPlayerInGame;
        std::vector<Bloc*> * blocs;
        int width;
        int height;
        bool standing;
};

#endif // ROOM_H_INCLUDED
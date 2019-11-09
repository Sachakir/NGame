#ifndef GRAPHICAL_H_INCLUDED
#define GRAPHICAL_H_INCLUDED

#include "room.hpp"
#include <SDL.h>

class Graphical
{
    public:
        Graphical(Room * room);
        ~Graphical();
        void show();
    private:
        SDL_Window * mainWindow;
        SDL_Renderer * renderer;
        Room * room;
        SDL_Rect * playerRect; //Rectangle representing a player
        SDL_Rect * otherPlayerRect; //Rectangle representing another player
};

#endif // GRAPHICAL_H_INCLUDED
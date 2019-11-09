#include "graphical.hpp"
#include <iostream>

using namespace std;

Graphical::Graphical(Room * room)
{
    Graphical::room = room;
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        SDL_Quit();
    }

    Graphical::mainWindow = SDL_CreateWindow
    (
        "NGame",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        Graphical::room->getWidth(),
        Graphical::room->getHeight(),
        SDL_WINDOW_SHOWN
    );

    Graphical::renderer = SDL_CreateRenderer
    (
        mainWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    
    playerRect = new SDL_Rect();
    playerRect->w = Graphical::room->getPlayer()->getWidth();
    playerRect->h = Graphical::room->getPlayer()->getHeight();

    otherPlayerRect = new SDL_Rect();
    otherPlayerRect->w = Graphical::room->getPlayer()->getWidth();
    otherPlayerRect->h = Graphical::room->getPlayer()->getHeight();
}

Graphical::~Graphical()
{
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyRenderer(renderer);
    delete playerRect;
    SDL_Quit();
}

void Graphical::show()
{
    //Repaint screen
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    //Repaint player
    playerRect->x = Graphical::room->getPlayer()->getX();
    playerRect->y = Graphical::room->getPlayer()->getY();
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderFillRect(renderer,playerRect);
    
    //Repaint other player
    otherPlayerRect->x = Graphical::room->getOtherPlayer()->getX();
    otherPlayerRect->y = Graphical::room->getOtherPlayer()->getY();
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,otherPlayerRect);

    //Repaint blocks
    SDL_SetRenderDrawColor(renderer,121,121,136,255);
    SDL_Rect * tmpBloc = new SDL_Rect();
    for (int i = 0;i < Graphical::room->getBlocs()->size();i++)
    {
        tmpBloc->w = (*Graphical::room->getBlocs())[i]->getWidth();
        tmpBloc->h = (*Graphical::room->getBlocs())[i]->getHeight();
        tmpBloc->x = (*Graphical::room->getBlocs())[i]->getX();
        tmpBloc->y = (*Graphical::room->getBlocs())[i]->getY();
        SDL_RenderFillRect(renderer,tmpBloc);
    }
    delete tmpBloc;

    //Refresh
    SDL_RenderPresent(renderer);
    //SDL_Delay(100);//TODO remove
}

#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include <SDL.h>

class Events
{
    public:
        Events();
        ~Events();
        int getEvent();
    private:
        SDL_Event * event;
};

enum moves 
{ 
    exit_game,
    left_move,
    right_move,
    jump_move,
    none
};

#endif // EVENTS_H_INCLUDED
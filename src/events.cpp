#include "events.hpp"

Events::Events()
{
    event = new SDL_Event();
}

Events::~Events()
{
    delete event;
}

int Events::getEvent()
{
    SDL_PollEvent(event);
    if (event->window.event == SDL_WINDOWEVENT_CLOSE)
    {
        return exit_game;
    }
    else if (event->type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_LEFT)
    {
        return left_move;
    }
    else if (event->type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_RIGHT)
    {
        return right_move;
    }
    else if (event->type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_SPACE)
    {
        return jump_move;
    }
    return none;
}
#include "room.hpp"
#include "graphical.hpp"
#include "events.hpp"
#include "physic.hpp"
#include <iostream>
#include "communication.hpp"
#include <string>
#include <sstream>
#include <thread>

using namespace std;

int main(int argc, char* argv[])
{ 
    //string otherIp = "127.0.0.1";
    string otherIp = argv[1];
    Room r;
    Communication * comm = new Communication(otherIp,&r);

    Graphical g(&r);
    Physic p(&r);
    Events events;
    int i = 0;
    int currentTime;
    int lastTime = SDL_GetTicks();
    int deltaTime;

    //receive coords
    std::thread t(&Communication::waitData, comm);
    
    while (1)
    {
        //Communication of coords
        string sendmsg = to_string(r.getPlayer()->getX());
        sendmsg = sendmsg + " ";
        sendmsg = sendmsg + to_string(r.getPlayer()->getY());
        comm->sendData(sendmsg);
        
        int res = events.getEvent();
        if (res == left_move)
        {
            p.moveLeft();
        }
        else if (res == right_move)
        {
            p.moveRight();
        }
        else if (res == jump_move)
        {
            p.moveUp();
        }
        else if (res == exit_game)
        {
            break;
        }
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        p.update(deltaTime);
        g.show();
        i++;
    }
    delete &r;
    return 0;
}
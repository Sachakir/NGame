#ifndef COMMUNICATION_H_INCLUDED
#define COMMUNICATION_H_INCLUDED

#include <winsock2.h>
#include <string>
#include "room.hpp"

class Communication
{
    public:
        Communication(std::string ipOtherPlayer,Room * room);
        ~Communication();
        void waitData();
        void sendData(std::string coords);
    private:
        WSADATA WSAData;
        SOCKET server;
        SOCKADDR_IN addr;
        SOCKADDR_IN otherPlayer;
        char buf[50];
        Room * room;
};

#endif // COMMUNICATION_H_INCLUDED
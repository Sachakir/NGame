#include "communication.hpp"
#include <iostream>
#include <Ws2tcpip.h>
#include <sstream>

using namespace std;

Communication::Communication(std::string ipOtherPlayer,Room * room)
{
    Communication::room = room;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    addr.sin_addr.s_addr = INADDR_ANY; // permet d'écouter sur toutes les interfaces locales
    addr.sin_port = htons(8888); // toujours penser à traduire le port en endianess réseau
    addr.sin_family = AF_INET; // notre adresse est IPv4
    int res = bind(server, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
    if (res < 0)
    {
        cout << "NOT BINDED !" << endl;
    }
    //Second player
    otherPlayer.sin_family = AF_INET;
    otherPlayer.sin_port = htons(8888);
    otherPlayer.sin_addr.s_addr = inet_addr(ipOtherPlayer.c_str());

    cout << "Communication created" << endl;
}

Communication::~Communication()
{
    closesocket(server);
    WSACleanup();
}

void Communication::waitData()
{
    while(1)
    {
        cout << "waitData !!" << endl;
        memset(buf, 0, 50);
        socklen_t fromlen = sizeof(otherPlayer);
        int ret = recvfrom(server, buf, 50, 0, reinterpret_cast<sockaddr*>(&otherPlayer), &fromlen);
        if (ret <= 0)
        {
            cout << "Error recv()" << endl;
        }
        else
        {
            istringstream iss(buf);
            string sx;
            string sy;
            getline( iss, sx,' ');
            getline( iss, sy,' ');
            room->getOtherPlayer()->setX(stoi(sx));
            room->getOtherPlayer()->setY(stoi(sy));

        }
        
    }
}


void Communication::sendData(std::string coords)
{
    int ret = sendto(server, coords.c_str(), 10, 0, reinterpret_cast<const sockaddr*>(&otherPlayer), sizeof(otherPlayer));
    if (ret < 0)
    {
        cout << "Error send()" << endl;
    }
}
//
// Created by Joseph González Pastora on 11/25/18.
//

#ifndef TECMEDIAFILESYSTEM_SOCKET_H
#define TECMEDIAFILESYSTEM_SOCKET_H

#include <netinet/in.h>

class Socket {
protected:

    sockaddr_in serverAdress;
    sockaddr_in clientAdress;
    socklen_t clientLenght;
    char buffer[256];

    //Construcctor privado, para que no se instancie
    Socket(){};




};

#endif //TECMEDIAFILESYSTEM_SOCKET_H

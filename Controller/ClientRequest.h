//
// Created by gabriel on 25/11/18.
//

#ifndef TECMEDIAFILESYSTEM_CLIENTREQUEST_H
#define TECMEDIAFILESYSTEM_CLIENTREQUEST_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include "../Model/Socket.h"
#include "../Model/Manager.h"

using json = nlohmann::json;

class ClientRequest : Socket {
private:
    std::string request(json op);

    //SocketClient client;
    int serverSocket;
    int portNumber;
    int client;
    Manager manager;
    ClientRequest(ClientRequest const&){};





public:

    void send(std::string jsonMessage);
    void getClient();
    ClientRequest();

    static ClientRequest* getInstance();

};
#endif //TECMEDIAFILESYSTEM_CLIENTREQUEST_H

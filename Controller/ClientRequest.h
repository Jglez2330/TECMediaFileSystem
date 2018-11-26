//
// Created by gabriel on 25/11/18.
//

#ifndef TECMEDIAFILESYSTEM_CLIENTREQUEST_H
#define TECMEDIAFILESYSTEM_CLIENTREQUEST_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "../Model/json.hpp"
#include "../Model/Manager.h"

using json = nlohmann::json;

#define PORT 8080

class ClientRequest {
private:
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    bool fileDescriptor();
    bool serverListen();
    std::string request(json op);
    Manager manager;
public:
    ClientRequest();
};
#endif //TECMEDIAFILESYSTEM_CLIENTREQUEST_H

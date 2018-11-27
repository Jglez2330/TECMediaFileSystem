//
// Created by Joseph González Pastora on 11/25/18.
//

#ifndef TECMEDIAFILESYSTEM_DISKCONTROLLER_H
#define TECMEDIAFILESYSTEM_DISKCONTROLLER_H


#include <string>
#include "Socket.h"
#include "json.hpp"
using json = nlohmann::json;

class DiskController : Socket {
public:

    void error(char *error);
    static DiskController* getInstance();
    std::string listenClient();
    std::string getClientXML();
    void send(json clientJson);





private:
    //SocketClient client;
    int serverSocket;
    int portNumber;
    int client;
    char buffer[1024*1024];
    static DiskController* serverSocketInstancePTR;
    DiskController(DiskController const&){};



    DiskController();



    char *split(char *ToSplit, char Delimeter);
};



#endif //TECMEDIAFILESYSTEM_DISKCONTROLLER_H

//
// Created by gabriel on 25/11/18.
//

#include <iostream>
#include "ClientRequest.h"



inline const char * const BoolToString(bool b){
    return b ? "true" : "false";
}
ClientRequest::ClientRequest(){
    //Crea un socket de tipo AF_INET, con un stream de datos
    this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
    //bzero((char *)&serverSocket, sizeof(serverSocket));
    this->portNumber = atoi("8080");
    //Asigna variables del socket y el tipo
    this->serverAdress.sin_family = AF_INET;
    this->serverAdress.sin_addr.s_addr = INADDR_ANY;
    this->serverAdress.sin_port = htons(this->portNumber);
    //Relaciona el socket con un puerto en la tarjeta de red de la computadora
    bind(serverSocket,(struct sockaddr*)&serverAdress, sizeof(serverAdress));





//Acepta el cliente,
    listen(serverSocket,5);
    this->clientLenght = sizeof(this->clientAdress);
    this->client = accept(this->serverSocket,(struct sockaddr*)&clientAdress,&clientLenght);

}


std::string ClientRequest::request(json op) {
    if (op["Opcode"] == 0)
        return BoolToString(manager.addVideo(op));
    else if(op["Opcode"] == 1)
        return manager.searchVideo(op["Name"]);
    else if(op["Opcode"] == 2)
        return BoolToString(manager.changeMetadata(op["Name"],op));
    else if(op["Opcode"] == 3)
        return BoolToString(manager.deleteVideo(op["Name"]));
    else
        std::cout << "Enter a valid Opcode" << std::endl;
}



void ClientRequest::send(std::string clientJson) {

    write(this->client,clientJson.data(), clientJson.size());
    char* c = new char(4);
    write(this->client,c, sizeof(char));
    delete(c);
}

void ClientRequest::getClient() {
while (true) {
    bool isClientMessageComplete = false;
    char bufferByte[1];
    std::string message = "";
    int status;
    while (!isClientMessageComplete) {
        read(this->client, bufferByte, 1);


        if ((int) bufferByte[0] == 0x4) {
            message + '\n';
            break;
        }
        if (bufferByte[0] != 0x0) {
            message.push_back(bufferByte[0]);
        }

    }

    json gson = json::parse(message);
    auto s = request(gson);

    send(s);
}
    return;
}
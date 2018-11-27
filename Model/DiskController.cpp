//
// Created by Joseph González Pastora on 11/25/18.
//

#include <iostream>
#include <thread>
#include "DiskController.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "../Model/json.hpp"

using json = nlohmann::json;

DiskController* DiskController::serverSocketInstancePTR = nullptr;

void DiskController::error(char *error) {
    perror(error);
    exit(1);


}

DiskController * DiskController::getInstance() {
    if (DiskController::serverSocketInstancePTR == nullptr){
        DiskController::serverSocketInstancePTR = new DiskController();
    }
    return DiskController::serverSocketInstancePTR;

}


DiskController::DiskController() {
    //Crea un socket de tipo AF_INET, con un stream de datos
    this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
    //bzero((char *)&serverSocket, sizeof(serverSocket));
    this->portNumber = atoi("5555");
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

std::string DiskController::getClient() {

    bool isClientMessageComplete = false;
    char bufferByte[1];
    std::string message = "";
    int status;
    while (!isClientMessageComplete){
        read(this->client, bufferByte,1);


        if ((int)bufferByte[0] == 0x4){
            message + '\n';
            break;
        }
        if (bufferByte[0] != 0x0) {
            message.push_back(bufferByte[0]);
        }

    }


    return message;
}

std::string DiskController::listenClient() {

    auto jsonMessage = json::parse(getClient());

    int opcode = jsonMessage["opcode"];

    switch(opcode) {


    }



}


void DiskController::send(json clientJson) {
    long long size = strlen(clientJson.dump().data());

    write(this->client,clientJson.dump().data(), size);
    char* c = new char(4);
    write(this->client,c, sizeof(char));
    delete(c);


}

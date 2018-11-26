//
// Created by gabriel on 25/11/18.
//

#include <iostream>
#include "ClientRequest.h"
inline const char * const BoolToString(bool b){
    return b ? "true" : "false";
}
ClientRequest::ClientRequest(){
    while (true){
        if (fileDescriptor())
            if(serverListen()){
                valread = read( new_socket , buffer, 1024);
                printf("%s\n",buffer );
                json jreturn = json::parse(buffer);
                std::string sendMessage = request(jreturn);
                send(new_socket , sendMessage.c_str() , strlen(sendMessage.c_str()) , 0 );
                std::cout << sendMessage << " sent" <<  std::endl;
            }
    }

}
bool ClientRequest::serverListen() {
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}
bool ClientRequest::fileDescriptor() {
    try{
        std::cout << "Loading Server..." << std::endl;
        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                       &opt, sizeof(opt)))
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons( PORT );
        return true;
    }catch (int e){
        return false;
    }
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

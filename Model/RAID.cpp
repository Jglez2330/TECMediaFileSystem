//
// Created by Joseph González Pastora on 11/17/18.
//

#include <fstream>
#include "RAID.h"
#include <cstring>
#include <iostream>
#include "json.hpp"
#include "DiskController.h"

using json = nlohmann::json;

RAID::RAID() {

}


std::string RAID::read(std::string code) {

    json jsonRequest = {{"opcode",1},{"videoCode",code}};

    DiskController* d = DiskController::getInstance();

    d->send(jsonRequest);

    json jsonResponse = json::parse(d->getClientXML());


    if (jsonResponse["data1"] == "nullptr"){
        return recontructData(jsonResponse["data2"],jsonResponse["data3"],jsonResponse["data4"],1);

    }else if (jsonResponse["data2"] == "nullptr"){
        return recontructData(jsonResponse["data1"],jsonResponse["data3"],jsonResponse["data4"],2);

    } else if (jsonResponse["data3"] == "nullptr") {
        return recontructData(jsonResponse["data1"], jsonResponse["data2"], jsonResponse["data4"],3);
    } else{
        return recontructData(jsonResponse["data1"], jsonResponse["data2"], jsonResponse["data3"],0);
    }




}

bool RAID::write(char *video, long long length, std::string Path) {
    unsigned char* videoFile = (unsigned char *) video;
    long long size = length;

    unsigned char* filepart1 = splitChar(videoFile, 0, size/3);
    unsigned char* filepart2 = splitChar(videoFile, size/3 , 2*size/3);
    unsigned char* filepart3 = splitChar(videoFile, 2*size/3 , size);
    unsigned char* filepart4 = parityXOR(filepart1,filepart2,filepart3, size/3);

    std::string string1 ((char*)filepart1, ((char*)filepart1) + strlen((char*)filepart1));
    std::string string2 ((char*)filepart2, ((char*)filepart2) + strlen((char*)filepart2));
    std::string string3 ((char*)filepart3, ((char*)filepart3) + strlen((char*)filepart3));
    std::string string4 ((char*)filepart4, ((char*)filepart4) + strlen((char*)filepart4));

    json jsonWrite = {{"opcode",0},{"data1",string1},{"data2",string2},{"data3",string3},{"parity",string4}};


    DiskController* d = DiskController::getInstance();
    d->send(jsonWrite);

    json clientResponse = d->getClientXML();

    return clientResponse["saved"] == "true";


}

std::string RAID::recontructData(std::string disk1, std::string disk2, std::string disk3, int diskFailure) {
    std::string missingPart((char*)(parityXOR((unsigned char*)disk1.data(),(unsigned char*)disk2.data(),(unsigned char*) disk3.data(),disk1.size())));
    std::string response;
    switch (diskFailure){
        case 0:
            response = disk1 + disk2 + disk3;
            break;
        case 1:
            response = missingPart + disk1 + disk2;
            break;
        case 2:
            response = disk1 + missingPart + disk2;
            break;
        case 3:
            response = disk1 + disk2 + missingPart;
            break;
    }
    return response;
}

unsigned char * RAID::parityXOR(unsigned char *partOfFile1, unsigned char *partOfFile2, unsigned char *partOfFile3, long long size) {
    unsigned char* parity = XOR(partOfFile1,partOfFile2, size);

    parity = XOR(parity,partOfFile3, size);

    return parity;


}

unsigned char * RAID::XOR(unsigned char *partOfFile1, unsigned char *partOfFile2, long long size) {
    unsigned char* parity = new unsigned char[size];

    for (int i = 0; i < size; i++) {
        parity[i] = partOfFile1[i] ^ partOfFile2[i];

    }

    return parity;
}

unsigned char * RAID::splitChar(unsigned char *file, long long int i, long long int final) {

    unsigned char* filePart = new unsigned char[final - i];
    int index = 0;
    for (long long j = i; j < final; j++) {
        filePart[index] = file[j];
        index++;
    }
    return filePart;
}


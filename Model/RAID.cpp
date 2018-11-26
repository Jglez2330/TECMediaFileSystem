//
// Created by Joseph González Pastora on 11/17/18.
//

#include <fstream>
#include "RAID.h"
#include <cstring>
#include <iostream>

RAID::RAID() {

}

unsigned char * RAID::read(char *path) {

    VideoFile videoFile  = VideoFile("1.mp4");
    VideoFile videoFile1 = VideoFile("2.mp4");
    VideoFile videoFile2 = VideoFile("3.mp4");
    long long size = videoFile.getLength();






    std::ofstream out5 ("6.mp4",std::ios::binary);

    for (int i = 0; i <size ; i++) {
        out5 << videoFile.getVideo()[i];

    }for (int i = 0; i <size ; i++) {
        out5 << videoFile1.getVideo()[i];

    }for (int i = 0; i <size ; i++) {
        out5 << videoFile2.getVideo()[i];

    }

    out5.close();


    return nullptr;
}

unsigned char* RAID::write(char *video,long long length, std::string Path) {
    unsigned char* videoFile = (unsigned char *) video;
    long long size = length;

    unsigned char* filepart1 = splitChar(videoFile, 0, size/3);
    unsigned char* filepart2 = splitChar(videoFile, size/3 , 2*size/3);
    unsigned char* filepart3 = splitChar(videoFile, 2*size/3 , size);
    unsigned char* filepart4 = parityXOR(filepart1,filepart2,filepart3, size/3);
    unsigned char* filepart5 = parityXOR(filepart2,filepart3,filepart4, size/3);

    std::ofstream out1 ("1.mp4",std::ios::binary);
    std::ofstream out2 ("2.mp4",std::ios::binary);
    std::ofstream out3 ("3.mp4",std::ios::binary);
    std::ofstream out4 ("4.mp4",std::ios::binary);
    std::ofstream out5 ("5.mp4",std::ios::binary);

    for (int i = 0; i <size/3; i++) {
        out1 << filepart1[i];

    }for (int i = 0; i <size/3; i++) {
        out2 << filepart2[i];

    }for (int i = 0; i <size/3; i++) {
        out3 << filepart3[i];

    }for (int i = 0; i <size/3; i++) {
        out4 << filepart4[i];

    }


    out1.close();
    out2.close();
    out3.close();
    out4.close();
    out5.close();








    return nullptr;
}

bool RAID::recontructData(int diskFailure) {






    return false;
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
    for (int j = i; j < final; j++) {
        filePart[index] = file[j];
        index++;
    }
    return filePart;
}


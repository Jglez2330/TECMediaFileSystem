//
// Created by Joseph González Pastora on 11/17/18.
//

#include <fstream>
#include "RAID.h"
#include <cstring>
RAID::RAID() {

}

unsigned char * RAID::read(char *path) {


    return nullptr;
}

unsigned char* RAID::write(VideoFile *video, char *Path) {
    unsigned char* videoFile = video->getVideo();
    int size = video->getLength();

    unsigned char* filepart1 = splitChar(videoFile, 0, size/3);
    unsigned char* filepart2 = splitChar(videoFile, size/3 , 2*size/3);
    unsigned char* filepart3 = splitChar(videoFile, 2*size/3 , size);
    unsigned char* filepart4 = parityXOR(filepart1,filepart2,filepart3);
    unsigned char* filepart5 = parityXOR(filepart1,filepart2,filepart4);
    unsigned char* filepart6 = parityXOR(filepart3,filepart2,filepart4);



    FILE* file1 = fopen("1.txt","wb+");
    FILE* file2 = fopen("2.txt","wb+");
    FILE* file3 = fopen("3.txt","wb+");
    FILE* file4 = fopen("4.txt","wb+");
    FILE* file5 = fopen("5.txt","wb+");

    fwrite(filepart1,sizeof(unsigned char), sizeof(filepart1), file1);
    fwrite(filepart2,sizeof(unsigned char), sizeof(filepart1), file2);
    fwrite(filepart3,sizeof(unsigned char), sizeof(filepart1), file3);
    fwrite(filepart4,sizeof(unsigned char), sizeof(filepart1), file4);
    fwrite(videoFile,sizeof(unsigned char), sizeof(videoFile), file5);






    return nullptr;
}

bool RAID::recontructData(int diskFailure) {




    return false;
}

unsigned char * RAID::parityXOR(unsigned char* partOfFile1, unsigned char* partOfFile2, unsigned char* partOfFile3) {
    unsigned char* parity = XOR(partOfFile1,partOfFile2);

    parity = XOR(parity,partOfFile3);

    return parity;


}

unsigned char *RAID::XOR(unsigned char *partOfFile1, unsigned char *partOfFile2) {
    int size = sizeof(partOfFile1) / sizeof(unsigned char);
    unsigned char* parity = new unsigned char[size];

    for (int i = 0; i < size; i++) {
        parity[i] = partOfFile1[i] ^ partOfFile2[i];

    }

    return parity;
}

unsigned char *RAID::splitChar(unsigned char *file, int i, int final) {
    unsigned char* filePart = new unsigned char[final - i];
    int index = 0;
    for (int j = i; j < final; j++) {
        filePart[index] = file[j];
        index++;
    }
    return filePart;
}


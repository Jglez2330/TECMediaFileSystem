#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>
#include "Raid/RAID.h"
#import "Raid/VideoFile.h"

int main() {
    //Change Path
    VideoFile vid = VideoFile("/home/gabriel/Desktop/Proyecto3/TECMediaFileSystem/Prueba.mp4");

    unsigned char hola[12]= {'A','B','C','D','E','F','G','H','T','Z','X','Y'};

    RAID::write(vid.getVideo(),"Hola");



    unsigned char* a = new unsigned char('A');
    unsigned char* b = new unsigned char('B');
    unsigned char* c = new unsigned char('C');
    std::cout<< a;
    std::cout<< b;
    std::cout<< c;
    std::cout << RAID::parityXOR(a,b,c);


    return 0;
}
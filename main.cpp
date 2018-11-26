#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>
#include "Model/RAID.h"
#import "Model/VideoFile.h"

int main() {
    //Change Path
    VideoFile* vid = new VideoFile("Prueba.mp4");









    RAID::write(vid,"Hola");
    RAID::read("");



    return 0;
}
#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>
#include "Raid/RAID.h"
#import "Raid/VideoFile.h"

int main() {
    //Change Path
    VideoFile* vid = new VideoFile("Prueba.mp4");









    RAID::write(vid,"Hola");



    return 0;
}
//
// Created by Joseph González Pastora on 11/17/18.
//

#ifndef TECMEDIAFILESYSTEM_RAID_H
#define TECMEDIAFILESYSTEM_RAID_H

#include "VideoFile.h"
class RAID {

public:

    static unsigned char * write(unsigned char *videoFile, char *Path);
    static unsigned char * read(char *path);
    static bool  recontructData(int diskFailure);
    /**
     * Calculates the exclusive or parity of the fourth file
     * @param partOfFile1 first part of the file
     * @param partOfFile2 second part of the file
     * @param partOfFile3 third part of the file
     * @return returns The exclusive or parity of the missing part of the file
     */
    static unsigned char * parityXOR(unsigned char *partOfFile1, unsigned char *partOfFile2, unsigned char *partOfFile3);

private:
    /**
     * Funtion that calculates the exclusive or of the parts of the files
     * @param partOfFile1 One part of the complete file
     * @param partOfFile2 Another part of the complete file
     * @return return the exclusive or of the partOfFile1 and partOfFile2
     */
    static unsigned char* XOR(unsigned char* partOfFile1 , unsigned char* partOfFile2);
    RAID();


    static unsigned char *splitChar(unsigned char *file, int i, int final);
};


#endif //TECMEDIAFILESYSTEM_RAID_H

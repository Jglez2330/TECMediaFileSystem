//
// Created by Joseph González Pastora on 11/21/18.
//

#ifndef TECMEDIAFILESYSTEM_VIDEOFILE_H
#define TECMEDIAFILESYSTEM_VIDEOFILE_H

#include <istream>

class VideoFile : public std::istream {

public:
    VideoFile(char* path,int r );
    

};


#endif //TECMEDIAFILESYSTEM_VIDEOFILE_H

//
// Created by Joseph González Pastora on 11/21/18.
//

#ifndef TECMEDIAFILESYSTEM_VIDEOFILE_H
#define TECMEDIAFILESYSTEM_VIDEOFILE_H

#include <istream>

class VideoFile{

public:

    /**
     * Function that gets the video and create a Unsigned Char Array
     * @param path
     * @param r
     */
    VideoFile(char* path);

    unsigned char *getVideo() const;

    void setVideo(unsigned char *video);
    //Getters and Setters

private:
    unsigned char * video;
    

};


#endif //TECMEDIAFILESYSTEM_VIDEOFILE_H

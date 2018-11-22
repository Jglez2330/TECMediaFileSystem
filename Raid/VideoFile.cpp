//
// Created by Joseph González Pastora on 11/21/18.
//
#include <fstream>
#include <iostream>


#include "VideoFile.h"
VideoFile::VideoFile(char* path){
    std::fstream mp4;
    mp4.open(path,std::fstream::in | std::fstream::out | std::fstream::app);
    mp4.seekg(0,mp4.end);
    length = mp4.tellg();
    mp4.seekg(0,mp4.beg);

    char * buffer = new char [length];

    mp4.read(buffer,length);
    video = (unsigned char *) buffer;
    std::cout << "video" << std::endl;
    for (int i = 0; i < length; i++ )
        std::cout << video[i];
    mp4.close();
}

unsigned char *VideoFile::getVideo() const {
    return video;
}

void VideoFile::setVideo(unsigned char *video) {
    VideoFile::video = video;
}

int VideoFile::getLength() const {
    return length;
}

void VideoFile::setLength(int length) {
    VideoFile::length = length;
}

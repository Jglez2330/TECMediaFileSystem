//
// Created by Joseph González Pastora on 11/21/18.
//
#include <fstream>
#include <iostream>


#include "VideoFile.h"
VideoFile::VideoFile(char* path){
    std::fstream mp4;
    mp4.open(path,std::fstream::in | std::fstream::binary | std::fstream::app);
    mp4.seekg(0,mp4.end);
    length = mp4.tellg();
    mp4.seekg(0,mp4.beg);


    /*FILE* fileVideo = fopen(path,"rb");
    fseek(fileVideo,0,SEEK_END);
    length = ftell(fileVideo);
    rewind(fileVideo);

    char * buffer = new char [length];
    fread(buffer,length,1,fileVideo);
    fclose(fileVideo);*/

    char * buffer = new char [length];




    mp4.read(buffer,length);
    video = (unsigned char*) buffer;
    std::cout << "video" << std::endl;
    for (int i = 0; i < length; i++ )
        std::cout << (char)video[i];
    mp4.close();
}

unsigned char * VideoFile::getVideo() const {
    return video;
}

void VideoFile::setVideo(unsigned char *video) {
    VideoFile::video = video;
}

long long VideoFile::getLength() const {
    return length;
}

void VideoFile::setLength(int length) {
    VideoFile::length = length;
}

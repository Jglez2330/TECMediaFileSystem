//
// Created by Joseph González Pastora on 11/21/18.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include "RAID.h"

#include "VideoFile.h"
VideoFile::VideoFile(char* path){
    //Opens the file
    std::fstream mp4;
    mp4.open(path,std::fstream::in | std::fstream::binary | std::fstream::app);
    mp4.seekg(0,mp4.end);
    long long length = mp4.tellg();
    mp4.seekg(0,mp4.beg);
    //Creates a buffer to store the file
    char * buffer = new char [length];
    //Reads the file
    mp4.read(buffer,length);
    //Writes the file to the memory
    Code = gencode();
    RAID::write(buffer,length, Code);
    //Closes the file
    mp4.close();
}
std::string VideoFile::gencode() {
    size_t length = 6;
    auto randchar =  []() -> char{
        const char charset [] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset [ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n(str.begin(),length,randchar);
    std::cout << "code:" << str << std::endl;
    return str;
}
//Getters and Setters

const std::string &VideoFile::getName() const {
    return Name;
}

void VideoFile::setName(const std::string &Name) {
    VideoFile::Name = Name;
}

const std::string &VideoFile::getDate() const {
    return Date;
}

void VideoFile::setDate(const std::string &Date) {
    VideoFile::Date = Date;
}

const std::string &VideoFile::getDirector() const {
    return Director;
}

void VideoFile::setDirector(const std::string &Director) {
    VideoFile::Director = Director;
}

const std::string &VideoFile::getDescription() const {
    return Description;
}

void VideoFile::setDescription(const std::string &Description) {
    VideoFile::Description = Description;
}

const std::string &VideoFile::getDuration() const {
    return Duration;
}

void VideoFile::setDuration(const std::string &Duration) {
    VideoFile::Duration = Duration;
}

const std::string &VideoFile::getCode() const {
    return Code;
}

void VideoFile::setCode(const std::string &Code) {
    VideoFile::Code = Code;
}

//Overloads
bool VideoFile::operator <(const VideoFile &v2){
    return (this->getCode() < v2.getCode());
}
bool VideoFile::operator >(const VideoFile &v2){
    return (this->getCode() > v2.getCode());
}
bool VideoFile::operator ==(const VideoFile &v2){
    return (this->getCode() == v2.getCode());
}
bool VideoFile::operator !=(const VideoFile &v2){
    return (this->getCode() != v2.getCode());
}



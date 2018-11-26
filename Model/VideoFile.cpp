//
// Created by Joseph González Pastora on 11/21/18.
//
#include <fstream>
#include <iostream>
#include <algorithm>
#include "RAID.h"

#include "VideoFile.h"
VideoFile::VideoFile(std::string video){
    long long length = video.size();
    //Writes the file to the memory
    Code = gencode();
    RAID::write(video.data(),length, Code);

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



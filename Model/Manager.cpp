//
// Created by Gabriel Abarca Aguilar on 23/11/18.
//
#include "VideoFile.h"
#include "Manager.h"
#include "RAID.h"

bool Manager::addVideo(json j){
    try {
        VideoFile* video = new VideoFile(j["VideoBytes"]);
        video->setName(j["Name"]);
        video->setDirector(j["Director"]);
        video->setDuration(j["Duration"]);
        video->setDescription(j["Description"]);
        video->setDate(j["Date"]);
        datamanagement->insert(video);
        return true;
    }
    catch (int e){
        return false;
    }
}
std::string Manager::searchVideo(std::string name){
    std::string code = datamanagement->getValue(name)->getCode();
    unsigned char * video = RAID::read(code);
    return std::string(video,video+strlen((char*) video));
}
bool Manager::changeMetadata(std::string name, json j){
    try {
        std::string vid = searchVideo(name);
        if (deleteVideo(name)){
            VideoFile* video = new VideoFile(vid);
            video->setName(j["Name"]);
            video->setDirector(j["Director"]);
            video->setDuration(j["Duration"]);
            video->setDescription(j["Description"]);
            video->setDate(j["Date"]);
            datamanagement->insert(video);
        }
        return true;
    }
    catch (int e){
        return false;
    }
}
bool Manager::deleteVideo(std::string name){
    try{
        datamanagement->deleteValue(name);
        return true;
    }catch (int e){
        return false;
    }
}
void Manager::printTreeInOrder(){
    datamanagement->inorder();
}
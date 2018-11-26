//
// Created by Gabriel Abarca Aguilar on 23/11/18.
//

#ifndef TECMEDIAFILESYSTEM_MANAGER_H
#define TECMEDIAFILESYSTEM_MANAGER_H


#include "RBTree.h"
#include "json.hpp"

using json = nlohmann::json;

class Manager {
private:
    RBTree* datamanagement;
public:
    Manager() {datamanagement = new RBTree;};
    bool addVideo(json j);
    std::string searchVideo(std::string name);
    bool changeMetadata(std::string name, json j);
    bool deleteVideo(std::string name);
    void printTreeInOrder();
};


#endif //TECMEDIAFILESYSTEM_MANAGER_H

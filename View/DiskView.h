//
// Created by gabriel on 26/11/18.
//

#ifndef TECMEDIAFILESYSTEM_DISKVIEW_H
#define TECMEDIAFILESYSTEM_DISKVIEW_H


#include <string>

class DiskView {
private:
    DiskView(){

    }
    static DiskView * UI;
    std::string disk1;
    std::string disk2;
    std::string disk3;
    std::string disk4;
public:
    static DiskView * singleton(){
        if (UI == NULL)
            UI = new DiskView();
        return UI;
    }
    void addDisk(unsigned  char * disk1, unsigned  char * disk2,unsigned  char * disk3,unsigned  char * disk4);
    void deleteDisk(unsigned  char * disk1, unsigned  char * disk2,unsigned  char * disk3,unsigned  char * disk4);
    void printDisk();
};


#endif //TECMEDIAFILESYSTEM_DISKVIEW_H

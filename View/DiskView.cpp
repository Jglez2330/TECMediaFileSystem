//
// Created by gabriel on 26/11/18.
//

#include <cstring>
#include <iostream>
#include "DiskView.h"
void DiskView::addDisk(unsigned  char * disk1, unsigned  char * disk2,unsigned  char * disk3,unsigned  char * disk4){
    this->disk1 = this->disk1 + std::string(disk1,disk1+strlen((char*) disk1));
    this->disk2 = this->disk2 + std::string(disk2,disk2+strlen((char*) disk2));
    this->disk3 = this->disk3 + std::string(disk3,disk3+strlen((char*) disk3));
    this->disk4 = this->disk4 + std::string(disk4,disk4+strlen((char*) disk4));
}
void DiskView::deleteDisk(unsigned  char * disk1, unsigned  char * disk2,unsigned  char * disk3,unsigned  char * disk4){
    //Disk 1
    std::string delete1 =  std::string(disk1,disk1+strlen((char*) disk1));
    this->disk1.erase(this->disk1.find(delete1),delete1.size());
    //Disk 2
    std::string delete2 =  std::string(disk2,disk2+strlen((char*) disk2));
    this->disk2.erase(this->disk2.find(delete2),delete2.size());
    //Disk 3
    std::string delete3 =  std::string(disk3,disk3+strlen((char*) disk3));
    this->disk3.erase(this->disk3.find(delete3),delete3.size());
    //Disk 4
    std::string delete4 =  std::string(disk4,disk4+strlen((char*) disk4));
    this->disk4.erase(this->disk4.find(delete4),delete4.size());
}

void DiskView::printDisk(){
    std::cout <<"Disk 1"<<std::endl;
    std::cout <<disk1<<std::endl;
    std::cout <<"Disk 2"<<std::endl;
    std::cout <<disk2<<std::endl;
    std::cout <<"Disk 3"<<std::endl;
    std::cout <<disk3<<std::endl;
    std::cout <<"Disk 4"<<std::endl;
    std::cout <<disk4<<std::endl;
}
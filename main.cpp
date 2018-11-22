#include <iostream>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>
#include "Raid/RAID.h"

int main() {




    unsigned char hola[12]= {'A','B','C','D','E','F','G','H','T','Z','X','Y'};

    RAID::write(hola,"Hola");



    unsigned char* a = new unsigned char('A');
    unsigned char* b = new unsigned char('B');
    unsigned char* c = new unsigned char('C');
    std::cout<< a;
    std::cout<< b;
    std::cout<< c;
    std::cout << RAID::parityXOR(a,b,c);


    return 0;
}
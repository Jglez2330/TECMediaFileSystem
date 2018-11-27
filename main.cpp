#include <iostream>
#include "Controller/ClientRequest.h"
#include "Model/RAID.h"

int main() {
    ClientRequest;

    std::cout<<RAID::recontructData("ABN","C","@",3);
    unsigned char* a = new unsigned char('A');
    unsigned char* b = new unsigned char('B');
    unsigned char* c = new unsigned char('C');
    std::cout<<RAID::parityXOR(a,b,c,1);
    return 0;
}

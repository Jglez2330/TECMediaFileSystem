#include <iostream>
#include <ios>
#include "string"
#include <fstream>
#include <sstream>
#include <vector>
#include "Model/RAID.h"
#import "Model/VideoFile.h"
#include "Model/json.hpp"
#include "Model/Manager.h"
#include "Model/base64.h"

using json = nlohmann::json;

using namespace std;
int main() {

    fstream mp4;
    //AQUI BUSCO EL PUTO VIDEO
    mp4.open("Prueba.mp4",std::fstream::in | std::fstream::binary | std::fstream::app);
    //LARGO DEL VIDEO EN PUTOS BYTES
    mp4.seekg(0,mp4.end);
    long long length = mp4.tellg();
    mp4.seekg(0,mp4.beg);
    //AQUI ESTÁ EL PUTO ARRAY
    char * buffer = new char [length];
    //FUNCION DE LECTURA
    mp4.read(buffer,length);
    //AQUI CIERRO EL PUTO MP4
    mp4.close();
    //Change Path
    Manager man;
    json j;
    string VideoBytes(buffer,buffer+length);
    string encoded = base64_encode(reinterpret_cast<const unsigned char*>(VideoBytes.c_str()), VideoBytes.length());
    j["VideoBytes"] = encoded;
    j["Name"] = "Prueba";
    j["Director"] = "Gabo Rikolino";
    j["Duration"] = "7Mil Años";
    j["Description"] = "Cliente";
    j["Date"] = "LA FECHA DE HOY";

    man.addVideo(j);
    man.printTreeInOrder();
    std::cout<< man.searchVideo("Prueba");










    RAID::write(vid,"Hola");
    RAID::read("");



    return 0;
}

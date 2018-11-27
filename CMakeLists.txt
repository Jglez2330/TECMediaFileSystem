cmake_minimum_required(VERSION 3.12)
project(TECMediaFileSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(TECMediaFileSystem main.cpp Model/RAID.cpp Model/RAID.h Model/VideoFile.cpp Model/VideoFile.h Model/RBTree.cpp Model/RBTree.h Model/Manager.cpp Model/Manager.h Model/base64.cpp Model/base64.h Model/DiskController.cpp Model/DiskController.h Model/Socket.cpp Model/Socket.h Controller/ClientRequest.cpp Controller/ClientRequest.h View/DiskView.cpp View/DiskView.h Controller/tinystr.cpp Controller/tinystr.h Controller/tinyxml.cpp Controller/tinyxml.h Controller/tinyxmlerror.cpp Controller/tinyxmlparser.cpp)

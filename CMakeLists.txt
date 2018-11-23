cmake_minimum_required(VERSION 3.12)
project(TECMediaFileSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(TECMediaFileSystem main.cpp Model/RAID.cpp Model/RAID.h Model/VideoFile.cpp Model/VideoFile.h)

cmake_minimum_required(VERSION 3.12)
project(TECMediaFileSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(TECMediaFileSystem main.cpp Raid/RAID.cpp Raid/RAID.h Raid/VideoFile.cpp Raid/VideoFile.h)
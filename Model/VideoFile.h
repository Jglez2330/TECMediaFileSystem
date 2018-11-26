//
// Created by Joseph González Pastora on 11/21/18.
//

#ifndef TECMEDIAFILESYSTEM_VIDEOFILE_H
#define TECMEDIAFILESYSTEM_VIDEOFILE_H

#include <istream>
#include <cstring>

class VideoFile{

public:

    /**
     * Function that gets the video and create a Unsigned Char Array
     * @param path
     * @param r
     */
    VideoFile(std::string);
    //Getters and Setters
    long long getLength() const;
    void setLength(int length);
    const std::string &getName() const;
    void setName(const std::string &Name);
    void setLength(long long int length);
    const std::string &getDate() const;
    void setDate(const std::string &Date);
    const std::string &getDirector() const;
    void setDirector(const std::string &Director);
    const std::string &getDescription() const;
    void setDescription(const std::string &Description);
    const std::string &getDuration() const;
    void setDuration(const std::string &Duration);
    //Overloads
    bool operator <(const VideoFile &v2);
    bool operator >(const VideoFile &v2);
    bool operator ==(const VideoFile &v2);
    bool operator !=(const VideoFile &v2);

    const std::string &getCode() const;

    void setCode(const std::string &Code);

private:
    //Video Data
    std::string Date;
    std::string Director;
    std::string Description;
    std::string Name;
    std::string Duration;
    std::string Code;
    std::string gencode();
};


#endif //TECMEDIAFILESYSTEM_VIDEOFILE_H

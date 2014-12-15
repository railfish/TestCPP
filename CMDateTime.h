#ifndef CMDATETIME_H
#define CMDATETIME_H

#include <string>

class CMDateTime {
    private:
    short year = 0;
    unsigned char month = 0;
    unsigned char day = 0;
    unsigned char hour = 0;
    unsigned char minute = 0;
    unsigned char second = 0;

    public:
    CMDateTime();
    CMDateTime(const CMDateTime &other);
    CMDateTime(const std::string &format, const std::string value);
    std::string ToString();
    std::string ToString(const std::string format);
};

#endif

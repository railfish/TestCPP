#include <ctime>
#include <stdio.h>
#include <vector>
#include "CMDateTime.h"

using namespace std;

CMDateTime::CMDateTime() {

}

CMDateTime::CMDateTime(const CMDateTime &other) {
    year = other.year;
    month = other.month;
    day = other.day;
    hour = other.hour;
    minute = other.minute;
    second = other.second;
}

CMDateTime::CMDateTime(const string &format, const string value) {
    string::const_iterator f = format.begin();
    string::const_iterator v = value.begin();

    while (f != format.end()) {
        if (*f++ != '%') {
            v++;
            continue;
        }

        switch (*f++) {
            case 'Y':
                year = atoi(string(v, v + 4).c_str());
                v += 4;
                break;
            case 'm':
                month = atoi(string(v, v + 2).c_str());
                v += 2;
                break;
            case 'd':
                day = atoi(string(v, v + 2).c_str());
                v += 2;
                break;
            case 'H':
            case 'l':
                hour = atoi(string(v, v + 2).c_str());
                v += 2;
                break;
            case 'M':
                minute = atoi(string(v, v + 2).c_str());
                v += 2;
                break;
            case 'S':
                second = atoi(string(v, v + 2).c_str());
                v += 2;
                break;
            case 'n':
            case 't':
                v++;
                break;
            default:
                break;
        }
    }
}

string CMDateTime::ToString() {
    char buffer[256];

    sprintf(buffer, "%04d%02u%02u%02u%02u%02u", year, month, day, hour, minute, second);

    return string(buffer);
}

string CMDateTime::ToString(const string format) {
    vector<char> buffer(format.size() * 2);

    return string(&buffer[0]);
}

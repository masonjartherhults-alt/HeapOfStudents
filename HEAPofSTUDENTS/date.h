#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int month, day, year;

public:
    Date();
    void init(std::string dateString);
    void printDate();
};

#endif


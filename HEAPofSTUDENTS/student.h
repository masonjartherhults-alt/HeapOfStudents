#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName, lastName;
    Address address;
    Date birthdate, gradDate;
    int creditHours;

public:
    Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
};

#endif


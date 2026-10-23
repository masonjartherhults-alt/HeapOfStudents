#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName, lastName;
    Address* address;
    Date* birthdate;
    Date* gradDate;
    int creditHours;

public:
    Student();
    ~Student();
    Student(const Student&) = delete;
    Student& operator=(const Student&) = delete;

    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
    std::string getLastName();
    std::string getFirstName();
    int getCreditHours();
};

#endif

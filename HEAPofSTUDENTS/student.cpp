#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
    firstName = "";
    lastName = "";
    creditHours = 0;
    address = new Address();
    birthdate = new Date();
    gradDate = new Date();
}

Student::~Student(){
    delete address;
    delete birthdate;
    delete gradDate;
}

void Student::init(std::string studentString){
    std::stringstream ss(studentString);
    std::string street, city, state, zip;
    std::string birth, grad, credits;

    std::getline(ss, firstName, ',');
    std::getline(ss, lastName, ',');
    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
    std::getline(ss, birth, ',');
    std::getline(ss, grad, ',');
    std::getline(ss, credits);

    address->init(street, city, state, zip);
    birthdate->init(birth);
    gradDate->init(grad);
    creditHours = std::stoi(credits);
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();

    std::cout << "DOB: ";
    birthdate->printDate();

    std::cout << "Credits: " << creditHours << std::endl;
    std::cout << "____________________________________" << std::endl;
}

std::string Student::getLastFirst(){
    return lastName + ", " + firstName;
}

std::string Student::getLastName(){
    return lastName;
}

std::string Student::getFirstName(){
    return firstName;
}

int Student::getCreditHours(){
    return creditHours;
}



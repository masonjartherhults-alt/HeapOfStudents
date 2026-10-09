#include <iostream>
#include <sstream>
#include "date.h"

Date::Date(){
    month = 0;
    day = 0;
    year = 0;
}

void Date::init(std::string dateString){
    std::stringstream ss(dateString);
    std::string m, d, y;

    std::getline(ss, m, '/');
    std::getline(ss, d, '/');
    std::getline(ss, y);

    month = std::stoi(m);
    day = std::stoi(d);
    year = std::stoi(y);
}

void Date::printDate(){
    std::string months[] = {
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
    };

    if(month >= 1 && month <= 12){
	std::cout << months[month - 1] << " " << day << ", " << year << std::endl;
    } else {
	std::cout << "Invalid date" << std::endl;
    }
}


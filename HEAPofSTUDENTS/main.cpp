#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

bool sortLast(Student* a, Student* b);
bool sortFirst(Student* a, Student* b);
bool sortCredits(Student* a, Student*b);

int main(){
    std::vector<Student*> students;
    loadStudents(students);

    std::string choice = "";

    while (choice != "0"){
	choice = menu();

	if (choice == "1"){
	     showStudentNames(students);
	} else if (choice == "2"){
	    printStudents(students);
	} else if(choice == "3"){
            findStudent(students);
	} else if(choice == "4"){
	    std::sort(students.begin(), students.end(), sortLast);
        } else if(choice == "5"){
	    std::sort(students.begin(), students.end(), sortFirst);
	} else if(choice == "6"){
            std::sort(students.begin(), students.end(), sortCredits);
	} else if(choice != "0"){
	    std::cout << "Invalid choice." << std::endl;
	}
  }

  delStudents(students);
  return 0;

}

void loadStudents(std::vector<Student*>& students){
    std::ifstream file("students.csv");
    std::string line;

    if(!file.is_open()){
	std::cout << "Could not open students.csv" << std::endl;
	return;
    }

    while(std::getline(file, line)){
	if(!line.empty() && line.back() == '\r'){
	    line.pop_back();
	}

	if(!line.empty()){
	    Student* student = new Student();
	    student->init(line);
	    students.push_back(student);
	}
  }

    file.close();
 }

void printStudents(std::vector<Student*>& students){
    for(Student* student : students){
	student->printStudent();
    }
}

void showStudentNames(std::vector<Student*>& students){
    for(Student* student : students){
	std::cout << student->getLastFirst() << std::endl;
    }
}

void findStudent(std::vector<Student*>& students){
    std::string name;
    bool found = false;

    std::cout << "Last name of student: ";
    std::getline(std::cin, name);

    for(Student* student : students){
	if(student->getLastName().find(name) != std::string::npos){
            student->printStudent();
	    found = true;
        }
    }

    if(!found){
	std::cout << "No students found." << std::endl;
    }
}

void delStudents(std::vector<Student*>& students){
    for(Student* student : students){
	delete student;
	students.clear();
    }

    students.clear();
}

std::string menu(){
    std::string choice;

    std::cout << "\n0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << "4) sort by last name" << std::endl;
    std::cout << "5) sort by first name" << std::endl;
    std::cout << "6) sort by credit hours" << std::endl;
    std::cout << "\nPlease choose 0-6: ";

    if(!std::getline(std::cin, choice)){
	return "0";
    }

    return choice;

}

bool sortLast(Student* a, Student* b){
    return a->getLastName() < b->getLastName();
}

bool sortFirst(Student* a, Student* b){
    return a->getFirstName() < b->getFirstName();
}

bool sortCredits(Student* a, Student* b){
    return a->getCreditHours() > b->getCreditHours();
}


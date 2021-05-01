//
//  students.cpp
//  C 867 Task 1
//
//  Created by Denver Cantu on 4/21/21.
//

#include "students.hpp"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

inline Student::Student() { //default constructor
    studentAge = 0;
    lastName = "No Name";
    firstName = "No Name";
    studentId = "No ID";
    eMail = "No Email";
    this->daysToComplete = new int[3];

}
Student::Student(string studentId, string firstName, string lastName, string eMail, int studentAge, int daysToComplete[], DegreeProgram degreeProgram) {
    
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->eMail = eMail;
    this->studentAge = studentAge;
    this->daysToComplete = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

//Constructors for Mutators
inline void Student::SetstudentAge(int studentAge) {
    this->studentAge = studentAge;
    return;
}

inline void Student::SetlastName(string lastName) {
    this->lastName = lastName;
    return;
}

inline void Student::SetfirstName(string firstName) {
    this->firstName = firstName;
    return;
}

inline void Student::SetstudentId(std::string studentId) {
    this->studentId = studentId;
    return;
}
inline void Student::SeteMail(std::string eMail) {
    this->eMail = eMail;
    return;
}
inline void Student::SetdaysToComplete(int *daysToComplete) {
    
    for (int i = 0; i < 3; ++i)
    this->daysToComplete[i] = daysToComplete[i];
    return;
}
void Student::printRoster() {
    cout << "Student ID: " << GetstudentId();
    cout << "\t First name: " << GetfirstName();
    cout << "\t Last name: " << GetlastName();
    cout << "\t E-Mail Address: " << GeteMail();
    cout << "\t Student Age: " << GetstudentAge();
    cout << "\t Days in course: " << "{" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << endl;
    cout << "\t Degree Program: ";
    switch(degreeProgram) {
        case SECURITY :
            cout << "SECURITY";
            break;
        case NETWORK:
            cout << "NETWORK";
            break;
        case SOFTWARE:
            cout << "SOFTWARE";
            break;
        case INVALID:
            cout << "INVALID";
            break;
    }
    cout << endl;
    return;
}
//Constructors for Accessors
int Student::GetstudentAge() {
    return studentAge;
}
string Student::GetfirstName() {
    return firstName;
}
string Student::GetlastName() {
    return lastName;
}
string Student::GetstudentId() {
    return studentId;
}
string Student::GeteMail() {
    return eMail;
}
int* Student::GetdaysToComplete() {
    return daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}
Student::~Student(){
    delete[] daysToComplete;
}

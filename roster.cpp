//
//  roster.cpp
//  C 867 Task 1
//
//  Created by Denver Cantu on 4/21/21.
#include "students.hpp"
#include "roster.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Roster::Roster() { //Default constructor//
        
    for (int i = 0; i < 5; i++) {
            classRosterArray[i] = nullptr;
    }
}
void Roster::parseStudentData(const string stringData[5]) { //Parse studentData and create new student objects for each student //
    
    for (int i = 0; i < MAX_SIZE; i++) {
        vector<string> studentInfo;
        stringstream s_stream(stringData[i]);
        
        while (s_stream.good()) {
            string subStr;
            getline(s_stream, subStr, ',');
            studentInfo.push_back(subStr);
        }
        int age = (stoi(studentInfo[4]));
        int daysToComplete[3] = {stoi(studentInfo[5]), stoi(studentInfo[6]), stoi(studentInfo[7])};
        
            // convert string to enum
            DegreeProgram degreeProgram = INVALID;
            if (studentInfo[8].compare("SECURITY") == 0) {
                degreeProgram = SECURITY;
            }
            else if (studentInfo[8].compare("NETWORK") == 0){
                degreeProgram = NETWORK;
            }
            else if (studentInfo[8].compare("SOFTWARE") == 0){
                degreeProgram = SOFTWARE;
            }
            else{
                degreeProgram = INVALID;
            }
    classRosterArray[i] = new Student(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], age, daysToComplete, degreeProgram); //Create New Student Objects for each student//
    }
}
//Define add function and update the roster//
void Roster::add(string studentId, string firstName, string lastName, string eMail, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram) {
    
        int daysToComplete[3] = {daysToComplete1, daysToComplete2, daysToComplete3};
    
            classRosterArray[MAX_SIZE] = new Student(studentId, firstName, lastName, eMail, age, daysToComplete, degreeProgram);
    return;
 }


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    
    for (int i = 0; i < MAX_SIZE; i++)
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            cout << "\nPrint students by degree type: " << degreeProgram << endl;
            classRosterArray[i]->printRoster();
    }
}
//Valid emails should contain at "@" symbol, a "." and should not have any " ".//
void Roster::printinvalidEmails() {
    for (int i = 0; i < MAX_SIZE; i++) {
        bool atFound = false;
        bool spaceFound = false;
        bool periodFound = false;
        
        for (auto& ch : classRosterArray[i]->GeteMail()) {
            if (ch == '@') atFound = true;
            if (ch == ' ') spaceFound = true;
            if (ch == '.') periodFound = true;
        }
        
        if (atFound == false || spaceFound == true || periodFound == false) {
            cout << "Invalid Email Found: " << classRosterArray[i]->GeteMail() << endl;
        }
        }
    }
    
//Prints a tab-separated list of student data//
void Roster::printAll() {

            for (int i = 0; i < MAX_SIZE; i++) {
                classRosterArray[i]->printRoster();
            }
}
void Roster::printAverageDaysInCourse(string studentId) {
    
    for (int i = 0; i < MAX_SIZE; i++) {
        bool isStudentFound = false;
        
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetstudentId() == studentId) {
            isStudentFound = true;
            int *tempDays = classRosterArray[i]->GetdaysToComplete();
            int avg = 0;
            for (int j = 0; j < 3; ++j) {
                avg += tempDays[j];
            }
            cout << classRosterArray[i]->GetfirstName() << "'s average number of days in three courses is: " << avg / 3 << endl;
        }
        else if ((isStudentFound = false)) {
                    cout << "No students with ID number: " << studentId << " are found. Try again." << endl;
        }
    }
}
//Remove student object when called//
void Roster::remove(string studentId) {
    bool isFoundID = false;
    for (int i = 0; (i < MAX_SIZE) && !isFoundID; ++i) {
        if(classRosterArray[i]->GetstudentId() == studentId) {
            classRosterArray[i] = classRosterArray[MAX_SIZE- 1];
            isFoundID = true;
        }
    }
    if (isFoundID){
        cout << "\nStudent with ID: " << studentId << " deleted" << endl;
    }
    else {
        cout << "\nError: student with this ID does not exist" << endl;
    }
};

//Destructor//
Roster::~Roster() {
            cout << "Class Roster Destructor Called" << endl;
            delete[] classRosterArray;
            
}


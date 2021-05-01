//
//  roster.hpp
//  C 867 Task 1
//
//  Created by Denver Cantu on 4/21/21.
//

#ifndef roster_hpp
#define roster_hpp
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include "students.hpp"
#include <stdio.h>

using namespace std;

const int MAX_SIZE = 5;

class Roster {
public:
    Roster();
    Student* *classRosterArray = new Student*[MAX_SIZE]; //Create Array of Pointers to hold student data//
    void parseStudentData(const string stringData[5]);
    void add(string studentId, string firstName, string lastName, string eMail, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeprogram);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printinvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    ~Roster();
    
private:
    

};

#endif /* roster_hpp */

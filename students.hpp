//
//  students.hpp
//  C 867 Task 1
//
//  Created by Denver Cantu on 4/21/21.
//
#include <string>
#include <iostream>
#ifndef students_hpp
#define students_hpp
#include "degree.h"


using namespace std;

class Student {
public:
    Student();
    Student(string studentId, string firstName, string lastName, string eMail, int studentAge, int daysToComplete[], DegreeProgram degreeProgram);
    ~Student();
//Mutator
    void SetstudentId(string studentId);
    void SetfirstName(string firstName);
    void SetlastName(string lastName);
    void SeteMail(string eMail);
    void SetstudentAge(int studentAge);
    void SetdaysToComplete(int daysToComplete[]);
    void printRoster();
//Accessors
    string GetstudentId();
    string GetfirstName();
    string GetlastName();
    string GeteMail();
    int GetstudentAge();
    int* GetdaysToComplete();
    DegreeProgram GetDegreeProgram();
    
private:
    
    string studentId;
    string firstName;
    string lastName;
    string eMail;
    int studentAge;
    int *daysToComplete;
    DegreeProgram degreeProgram;
    
};
#endif /* students_hpp */

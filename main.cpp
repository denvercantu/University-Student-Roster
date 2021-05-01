//
//  main.cpp
//  C 867 Task 1
//
//  Created by Denver Cantu on 4/21/21.
//
#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include "roster.hpp"
#include "students.hpp"

using namespace std;

int main()
{

    cout << "C-867 Scripting and Programming" << endl;
    cout << "Language Used: C++" << endl;
    cout << "Student ID: #001539618" << endl;
    cout << "Denver Headings Cantu" << endl;
    
    //Create instance of the Roster class called classRoster//
    Roster* classRoster = new Roster ();
    
    //Add my student data to the studentData table//
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Denver,Headings,dheadin@wgu.edu,34,40,23,44,SOFTWARE"
    };
    //Parse student data and create new student objects//
    classRoster->parseStudentData(studentData);
                     
    //Convert pseudo code//
    cout << "\nPrinting Class Roster:" << endl;
    classRoster->printAll();
    
    //Print Invalid Emails//
    cout << "\nPrinting Invalid E-Mails:" << endl;
    classRoster->printinvalidEmails();
    
    //Loop through classRosterArray for each element//
    cout << "\nPrinting average # of days per course..." << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetstudentId());
    }
    //Print By Degree Program//
    classRoster->printByDegreeProgram(SOFTWARE);
    
    //Remove Student "A3"//
    classRoster->remove("A3");
    
    //Called Destructor//
    classRoster->~Roster();
    }


//
//  Student.hpp
//
//  CIS 22C-02Y
//  M/W 1:30 - 3:20
//  Professor Delia Gârbacea
//  Trinh Nguyen
//  February 26, 2017
//  Homework #4
//  IDE: Xcode

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <ostream>
using namespace std;

class Student; // Forward Declaration

class Student
{
private:
    int id;
    string name;
    double gpa;
    
public:
    Student() { id = 0; name = ""; gpa = 0.0; }
    Student(int id, string name, double gpa)
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }
    
    //Accessors
    void setID(int id)          { this->id = id; }
    void setName(string name)   { this->name = name; }
    void setGPA(double gpa)     { this->gpa = gpa; }
    
    //Mutators
    int getID()         { return id; }
    string getName()    { return name; }
    double getGPA()     { return gpa; }
    
    // Overloaded operator functions
    bool operator==(Student right)
    {
        if (id == right.getID()) return true;
        else return false;
    }
    bool operator<(Student right)
    {
        if (id < right.getID()) return true;
        else return false;
    }
    bool operator>(Student right)
    {
        if (id > right.getID()) return true;
        else return false;
    }
};

#endif /* Student_hpp */

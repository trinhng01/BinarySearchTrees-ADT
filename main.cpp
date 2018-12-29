// main test driver for BST
// Created by Frank M. Carrano and Tim Henry.
// Modified by Trinh Nguyen

//  CIS 22C-02Y
//  M/W 1:30 - 3:20
//  Professor Delia Gârbacea
//  Trinh Nguyen
//  February 26, 2017
//  Homework #5
//  IDE: Xcode

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stack>
#include "BinarySearchTree.h"  // BST ADT
#include "Student.hpp"
#include "Queue.h"
#include "Stack.h"
using namespace std;

const int MAX_SIZE = 200;

//Function Prototypes
void displayMenu();
char getChoice();
void readData(BinarySearchTree<Student> studentList, string filename);
void processActions(BinarySearchTree<Student> studentList);
void optionA();


int main()
{
    string filename = "gpa.txt";
    BinarySearchTree<Student> studentList;
    
    readData(studentList, filename);
    processActions(studentList);
    
    return 0;
}

void displayMenu()
{
    cout << "====== MENU OF SERVICES ======\n"
    "D – Depth-First Traversals: inorder, preorder, postorder\n"
    "I – Iterative Depth-First Traversals: inorder, preorder, postorder\n"
    "B – Tree Breadth-First Traversals: Print by level"
    "S – Search by the primary key\n"
    "M – Find the smallest\n"
    "X – Find the largest\n"
    "T – Print the BST as an indented list\n"
    "H – Help – to show the menu, and\n"
    "E – Exit.\n";
    return;
}

char getChoice()
{
    char choice;
    cout << "Your choice is ==> ";
    cin >> choice;
    choice = toupper(choice);
    if (choice != 'D' || choice != 'I' || choice != 'B' || choice != 'S' || choice != 'M' || choice != 'X' || choice != 'T' || choice != 'A' || choice != 'H' || choice != 'E')
    {
        cout << "Please enter a valid option following the menu provided above\n"
        "Your choice ==> ";
        choice = getChoice();
    }
    return choice;
}


void readData(BinarySearchTree<Student> list, string filename)
{
    string tempStr = "";
    int tempID = 0;
    double tempGPA = 0.0;
    char *ptr, line[MAX_SIZE];
    
    //Open input file
    ifstream inputfile;
    inputfile.open(filename);
    
    if(!inputfile.good())
    {
        cout <<"Error opening file!\n";
        exit(-1);
    }
    
    while (!inputfile.eof())
    {
        Student *dataIn = new Student;
        inputfile.getline(line, MAX_SIZE, '\n');
        
        if (strcmp(line,""))
        {
            //Read in Student ID
            ptr = strtok(line, " ");
            tempStr = ptr;
            tempID = stoi(tempStr);
            cout << tempID << endl;
            dataIn->setID(tempID);
            
            //Read in Student name
            ptr = strtok(NULL, ";");
            tempStr = ptr;
            cout << tempStr << endl;
            dataIn->setName(tempStr);
            
            //Read in Student GPA
            ptr = strtok(NULL, "");
            tempStr = ptr;
            tempGPA = stod(tempStr);
            cout << tempGPA << endl;
            dataIn->setGPA(tempGPA);
            
            
            inputfile.ignore();
            inputfile.clear();
            //Insert data into a BST
            list.insert(*dataIn);
        }
    }
    return;
}
void processActions(BinarySearchTree<Student> studentList){
    char choice;

    do{
        displayMenu();
        choice = getChoice();
        /**
        if (choice == 'D')
        else if(choice == 'I')
        else if(choice == 'B')
        else if(choice == 'S')
        else if(choice == 'M')
        else if(choice == 'X')
        else if(choice == 'T')
        else if(choice == 'A') optionA();
        else if(choice == 'H') displayMenu();*/
    }while (choice!= 'E');

}
void optionD()
{
    
}

void optionI()
{
    
}

void optionB()
{
    
}

void optionS()
{
    
}

void optionM()
{
    
}

void optionX()
{
    
}

void optionT()
{
    
}
void optionA()
{
    cout << "This program is created by Frank M. Carrano and Tim Henry"
    "and is modified by Trinh Nguyen\n";
}




















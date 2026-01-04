#ifndef CRUD_CPP
#define CRUD_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


//daniyal add your  functions  here

// function to add students in the file
void addStudents(const string &filename, const string &rollNumber, const string &newName,
                 const vector<int> &newMarks, float newAverage);

// function to update the file
void updateRecord(const string &filename, const string &rollNumber, const string &newName,
                  const vector<int> &newMarks, float newAverage);

// function to delete the file

void deleteRecord(const string &filename, const string &rollNumber);

#endif
// function to create the file
void createFile(const string &filename);

// Function to read the existing file
void readFile(const string &filename);

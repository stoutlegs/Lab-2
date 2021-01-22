// Filename: CCourse.h
// Description: Lab 2 - Grading CCourse C++ class header
// Author(s): Michael Andrews
// Set: S
// Date: Jan 20, 2021 (edited)

#pragma once

#include <iostream>
#include <vector>
#include "CStudent.h"

class CCourse {
private:
	std::vector<CStudent> students;

public:

//////////////////////////////////////////////////////////////////////////
// add_student - This function will create a new student in the vector
//				students and then call the edit_student function.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
	void add_student();

//////////////////////////////////////////////////////////////////////////
// edit_student - This function will prompt the user for student attributes
//				such as student number. It will call functions for error
//				checking.
// Arguments: int i - this is the vector index of the student to edit.
// Note: none
//////////////////////////////////////////////////////////////////////////
	void edit_student(int i);

//////////////////////////////////////////////////////////////////////////
// print_grades - This function will print all the students and their 
//				  attributes to be viewed by the operator.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
	void print_grades();

//////////////////////////////////////////////////////////////////////////
// delete_student - This function will delete a student for the vector,
//					subsequently shrinking the vector.
// Arguments: int i - this is the vector index of the student to delete.
// Note: none
//////////////////////////////////////////////////////////////////////////
	void delete_student(int i);

//////////////////////////////////////////////////////////////////////////
// save - this function will save all the student info to a file called
//		  "Students.txt". Th file is in the same folder as the .exe
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
	void save();

//////////////////////////////////////////////////////////////////////////
// load - This function will load all student info from the file called 
//		  "Students.txt" and overwrite any existing students in the 
//        vector.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
	void load();

//////////////////////////////////////////////////////////////////////////
// find_student - This function will take a string input from the user
//				  and check whether that student number exists in the
//				  vector.
// Arguments: std::string num - user input student number to find.
// Note: none
//////////////////////////////////////////////////////////////////////////
	int find_student(std::string num);

//////////////////////////////////////////////////////////////////////////
// num_check - This function will take a user input string and check if
//			   it can be converted to a float between 0.0-100.0
// Arguments: std::string num - user input string to be checked.
// Note: none
//////////////////////////////////////////////////////////////////////////
	bool num_check(std::string num);
};
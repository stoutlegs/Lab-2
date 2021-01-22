// Filename: CCourse.cpp
// Description: Lab 2 - Grading CCourse C++ class
// Author(s): Michael Andrews
// Set: S
// Date: Jan 20, 2021 (edited)

#include "CCourse.h"
#include "CStudent.h"
#include <fstream>
#include <iostream>
#include <sstream>


//////////////////////////////////////////////////////////////////////////
// add_student - This function will create a new student in the vector
//				students and then call the edit_student function.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::add_student() {
    
    CStudent newStudent;
    students.push_back(newStudent);

    bool flag = false;
    int i = students.size();
    i--;

    edit_student(i);
}

//////////////////////////////////////////////////////////////////////////
// edit_student - This function will prompt the user for student attributes
//				such as student number. It will call functions for error
//				checking.
// Arguments: int i - this is the vector index of the student to edit.
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::edit_student(int i) {

    bool flag = false;
    int num = -1;
    std::string strCheck;

        do {

            do {
                std::cout << "\nStudent Number: ";
                std::cin >> strCheck;

                if (students[i].studentNum != strCheck)
                {
                    num = find_student(strCheck);

                    if (num <= 0) {
                        students[i].studentNum = strCheck;
                        flag = true;

                    }
                    else {
                        std::cout << "\nThis student number already exists. Please try again.\n";
                        flag = false;
                    }
                }
                else {
                    flag = true;
                }
            } while (flag == false);

            if (students[i].studentNum.size() == 9) {

                if (students[i].studentNum.substr(0, 3) == "A00") {

                    flag = true;
                }
                else if (students[i].studentNum.substr(0, 3) == "A01") {

                    flag = true;
                }
                else {

                    std::cout << "\nThat is not a valid student number. Please try again.\n";
                    flag = false;
                }
            }
            else {

                std::cout << "\nThat is not a valid student number. Please try again.\n";
                flag = false;
            }
        } while (flag == false);

        bool tf;

        do {
            std::cout << "Lab Grade: ";
            std::cin >> strCheck;

            tf = num_check(strCheck);

        } while (tf == false);

        students[i].labGrade = std::stof(strCheck);

        do {

            std::cout << "Quiz Grade: ";
            std::cin >> strCheck;

            tf = num_check(strCheck);

        } while (tf == false);

        students[i].quizGrade = std::stof(strCheck);

        do {

            std::cout << "Midterm Grade: ";
            std::cin >> strCheck;

            tf = num_check(strCheck);

        } while (tf == false);

        students[i].midtermGrade = std::stof(strCheck);

        do {

            std::cout << "Final Exam Grade: ";
            std::cin >> strCheck;

            tf = num_check(strCheck);

        } while (tf == false);

        students[i].finalGrade = std::stof(strCheck);
}

//////////////////////////////////////////////////////////////////////////
// print_grades - This function will print all the students and their 
//				  attributes to be viewed by the operator.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::print_grades() {

    std::cout << "#\t\t";
    std::cout << "Student Num\t\t";
    std::cout << "Lab\t\t";
    std::cout << "Quiz\t\t";
    std::cout << "Midterm\t\t";
    std::cout << "Final Exam\t";
    std::cout << "Final Grade\n";

    for (int i = 0; i < students.size(); i++) {

        std::cout << i << "\t\t";
        std::cout << students[i].studentNum << "\t\t";
        std::cout << students[i].labGrade << "\t\t";
        std::cout << students[i].quizGrade << "\t\t";
        std::cout << students[i].midtermGrade << "\t\t";
        std::cout << students[i].finalGrade << "\t\t";
        std::cout << ((students[i].labGrade * 0.4) + (students[i].quizGrade * 0.1) + (students[i].midtermGrade * 0.2) + (students[i].finalGrade * 0.3)) << "\n";
    }

    std::cout << "\n";
}

//////////////////////////////////////////////////////////////////////////
// delete_student - This function will delete a student for the vector,
//					subsequently shrinking the vector.
// Arguments: int i - this is the vector index of the student to delete.
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::delete_student(int i) {

    students.erase(students.begin() + i);
}

//////////////////////////////////////////////////////////////////////////
// save - this function will save all the student info to a file called
//		  "Students.txt". Th file is in the same folder as the .exe
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::save() {
    
    std::ofstream outfile;

    outfile.open("Students.txt", std::ios::out);

    for (int i = 0; i < students.size(); i++) {
        outfile << students[i].studentNum << "\n";
        outfile << students[i].labGrade << "\n";
        outfile << students[i].quizGrade << "\n";
        outfile << students[i].midtermGrade << "\n";
        outfile << students[i].finalGrade << "\n";
    }

    outfile.close();
}

//////////////////////////////////////////////////////////////////////////
// load - This function will load all student info from the file called 
//		  "Students.txt" and overwrite any existing students in the 
//        vector.
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void CCourse::load() {

    std::vector<std::string> all_data;
    std::string line;
    std::ifstream infile("Students.txt");
    CStudent loadStudent;
    int i = 0;

    while (std::getline(infile, line)) { 
        all_data.push_back(line); 
    }     
    infile.close();   
    
    for (int i = 0; i < all_data.size(); i += 5) {

        if (i/5 >= students.size()) {
            students.push_back(loadStudent);
        }

        students[i/5].studentNum = all_data.at(i);
        students[i/5].labGrade = std::stof(all_data.at(i + 1));
        students[i/5].quizGrade = std::stof(all_data.at(i + 2));
        students[i/5].midtermGrade = std::stof(all_data.at(i + 3));
        students[i/5].finalGrade = std::stof(all_data.at(i + 4));
    }
}

//////////////////////////////////////////////////////////////////////////
// find_student - This function will take a string input from the user
//				  and check whether that student number exists in the
//				  vector.
// Arguments: std::string num - user input student number to find.
// Note: none
//////////////////////////////////////////////////////////////////////////
int CCourse::find_student(std::string num) {
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].studentNum == num)
        {
            return i;
        }
    }

    return -1;
}

//////////////////////////////////////////////////////////////////////////
// num_check - This function will take a user input string and check if
//			   it can be converted to a float between 0.0-100.0
// Arguments: std::string num - user input string to be checked.
// Note: none
//////////////////////////////////////////////////////////////////////////
bool CCourse::num_check(std::string num) {

    int countDecimal = 0;

    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '.') {
            countDecimal++;
        }

        if (isdigit(num[i]) == false and num[i] != '.') {
            std::cout << "\nThat is not a valid number. Please try again.\n\n";
            return false;
        }
    }

    if (countDecimal > 1) {
        std::cout << "\nThat is not a valid number. Please try again.\n\n";
        return false;
    }

    float numCheck = std::stof(num);

    if (numCheck > 0) {
        if (numCheck < 100) {
            return true;
        }
    }

    std::cout << "\nThat is not a valid number. Please try again.\n\n";
    return false;
}
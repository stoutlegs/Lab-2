// Filename: Lab 2.cpp
// Description: Lab 2 - Grading
// Author(s): Michael Andrews
// Set: S
// Date: Jan 20, 2021 (edited)

#include <iostream>
#include "CCourse.h"
#include "CStudent.h"
#include <fstream>

//////////////////////////////////////////////////////////////////////////
// print_menu - This function will print the main menu for the program
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void print_menu();

int main() {

	char input = NULL;
	int i = -1;
	std::string num;

	CCourse classroom;

	while (true) {

		print_menu();

		std::cin >> input;

		switch (input)
		{
		case 'A':
		case 'a':
			classroom.add_student();
			break;

		case 'E':
		case 'e':
			while (i < 0) {

				std::cout << "\nStudent Number of Student to Edit: ";
				std::cin >> num;

				i = classroom.find_student(num);

				if (i < 0) {

					std::cout << "\nThis student number does not exist. Please try again.\n";
				}
			}

			classroom.edit_student(i);
			i = -1;
			break;

		case 'D':
		case 'd':
			while (i < 0) {

				std::cout << "\nStudent Number of Student to Delete: ";
				std::cin >> num;

				i = classroom.find_student(num);

				if (i < 0) {

					std::cout << "\nThis student number does not exist. Please try again.\n";
				}
			}

			classroom.delete_student(i);
			i = -1;
			break;

		case 'P':
		case 'p':
			classroom.print_grades();
			break;

		case 'S':
		case 's':
			classroom.save();
			break;

		case 'L':
		case 'l':
			classroom.load();
			break;

		case 'Q':
		case 'q':
			exit(EXIT_SUCCESS);

		default:
			std::cout << "\nThat command is invalid. Please try again.\n\n";
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// print_menu - This function will print the main menu for the program
// Arguments: none
// Note: none
//////////////////////////////////////////////////////////////////////////
void print_menu() {
	std::cout << "****************************************\n";
	std::cout << "ELEX 4618 Grade System, by MIKE ANDREWS\n";
	std::cout << "****************************************\n\n";
	std::cout << "(A)dd Student\n";
	std::cout << "(E)dit Student\n";
	std::cout << "(P)rint Grades\n";
	std::cout << "(D)elete\n";
	std::cout << "(S)ave\n";
	std::cout << "(L)oad\n";
	std::cout << "(Q)uit\n";

	std::cout << "\nCMD> ";
}
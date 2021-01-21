#pragma once

#include <iostream>
#include <vector>
#include "CStudent.h"

class CCourse {
private:
	std::vector<CStudent> students;

public:
	void add_student();
	void edit_student(int i);
	void print_grades();
	void delete_student(int i);
	void save();
	void load();
	int find_student(std::string num);
	bool num_check(std::string num);
};
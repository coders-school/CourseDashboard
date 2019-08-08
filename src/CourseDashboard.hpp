#pragma once
#include "Student.hpp"
#include <vector>
#include <map>

class CourseDashboard
{
public:
    CourseDashboard();
	~CourseDashboard();

	void addStudent();
	//void showStudents();

	std::vector<Student> listOfStudents;
	std::map<Student, std::vector<int>> rating;
};

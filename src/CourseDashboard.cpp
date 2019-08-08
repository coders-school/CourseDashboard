#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>

CourseDashboard::CourseDashboard()
{

}

CourseDashboard::~CourseDashboard()
{

}

void CourseDashboard::addStudent()
{
	Student student;
    std::cout<< "\nName: ";
    std::cin>> student.name;
    std::cout<< "\nNick: ";
    std::cin>> student.nick;
    std::cout<< "\nEmail: ";
    std::cin>> student.eMail;

    this->listOfStudents.push_back(student);
    std::cout<< "Student: " << student.name << " has been assign to list." << std::endl;
}

/*
void CourseDashboard::showStudents()
{
	for (auto& it = listOfStudents.begin(); it != listOfStudents.end(); it++)
	{
		//std::cout << it->name << std::endl;
	}
}
*/

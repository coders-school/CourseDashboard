#include <iostream>
#include "CourseDashboard.hpp"
#include "Student.hpp"
#include <cstdlib>
#include <unistd.h>

int main()
{
	std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "-------------------------Course Dashboard----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	CourseDashboard dashboard;

	int ch = 0;

	do
	{
		std::system("clear");

		std::cout<< "1 - show list of students" <<std::endl;
		std::cout<< "2 - add student" << std::endl;
		std::cout<< "3 - remove student" << std::endl;
		std::cout<< "4 - view student" << std::endl;
		std::cout<< "5 - modify student" << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout<< "0 - exit" << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;

		std::cin>>ch;

		switch(ch)
		{
			case 1: 
				{
					//dashboard.showStudents();
					break;
				}
			case 2:
				{
					dashboard.addStudent();
					break;
				}
			case 3:
				{
					//std::string name;
					//std::cout<< "Who will be erase?" <<std::endl;
					//std::cin >> name;
					//dashboard.removeStudent(name);
					break;
				}
			default:
				{
					std::cout<< "Wrong selection, please pick one more time ;)" <<std::endl;
				}
		}
		sleep(3);
	}
	while (ch != 0);

	std::cout << "Bye!" <<std::endl;

    return 0;
}

#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include<algorithm>
#include <iterator>
#include <cstdlib>
#include <unistd.h>


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
    std::cout<< "\nPassword ";
    std::cin>> student.password;

    this->listOfStudents.push_back(student);
    std::cout<< "Student: " << student.name << " has been assign to list." << std::endl;
}


void CourseDashboard::showStudents()
{   
    std::system("clear");
    std::cout<<"List of Students"<<std::endl;
	for (int i=0;i<listOfStudents.size();i++)
	{
        //std::cout<<" AAASDAS";
        std::cout<< "Number of student "<< i<<" ";
		std::cout <<listOfStudents[i].name<< std::endl;
        std::cout <<listOfStudents[i].nick<< std::endl;
        std::cout <<listOfStudents[i].password<< std::endl;
        std::cout<<std::endl<<std::endl<<std::endl;
	}
    std::cout<<"The end of list of students.";
}

void CourseDashboard::login()
{
    std::system("clear");
	std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "-------------------------Course Dashboard----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
    std::string name;
    std::string password;
    bool test=false;
 
    do
    {   
        std::cout<<"Your Name"<<std::endl;
        std::cin>>name;
        std::cout<<std::endl<<"Your Password"<<std::endl;
        std::cin>>password;
        std::system("clear");
            std::vector <Trainer> ::iterator it = std::find_if (
            ListOfGoldFathers.begin(),
            ListOfGoldFathers.end(),
            [ name,password,&test](const Trainer & ListOfGoldFathers)
            {
                if( ListOfGoldFathers.name == name &&  ListOfGoldFathers.password == password )
                {
                    test=true;
                    return true;
                }
                else return false;
            });
            if(test==true)
            {
                std::cout<<"Logged : ";
                std::cout<<it->name;
                std::cout<<std::endl<<"Do, what you want to do"<<std::endl;
                this->panel(*it);
            }else
            {
                std::cout<<"Login or Password is incorect"<<std::endl<<"Try again";
            }
          
    
    }while(test==false);
   //   this->panel(*it);
    
}

void CourseDashboard::run()
{
    Trainer Lukasz ;
    Lukasz.name = "Lukasz1";
    Lukasz.password="Ziobron";
    ListOfGoldFathers.push_back(Lukasz);
    Lukasz.name = "Ola";
    Lukasz.password="Halapacz";
    ListOfGoldFathers.push_back(Lukasz);
    Lukasz.name = "Lukasz3";
    Lukasz.password="Ziobron";
    ListOfGoldFathers.push_back(Lukasz);
    this->login();
 
}
/*
bool CourseDashboard::checklog(std::string name,std::string password)
{
    return true;
}
*/
void CourseDashboard::panel(Trainer &T)
{
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
					this->showStudents();
					break;
				}
			case 2:
				{
					this->addStudent();
					break;
				}
			case 3:
				{
					int name;
					std::cout<< "Who will be erase?" <<std::endl;
					std::cin >> name;
					this->removeStudent(name);
					break;
				}
            case 4: 
                {
                    int num;
                    std::string change;
                    std::cout<<"Write number student to edit: ";
                    std::cin>>num;
                     std::cout<<"What do you want to change?";
                     std::cin>>change;
                     if(change=="name") 
                     {
                         std::cout<<"Write new name";
                         std::cin>>change;
                         listOfStudents[num].name=change;
                         break;
                     }
                     if(change=="nick") 
                     {
                         std::cout<<"Write new nick";
                         std::cin>>change;
                         listOfStudents[num].nick=change;
                         break;
                     }
                     if(change=="password") 
                     {
                         std::cout<<"Write new name";
                         std::cin>>change;
                         listOfStudents[num].password=change;
                         break;
                     }
                    
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

 

}
	void CourseDashboard::panel(Student &T)
{

}

void CourseDashboard::removeStudent(int num)
{
    int helpnum=0;
    for(auto it=listOfStudents.begin();it!=listOfStudents.end();it++)
    {
        if(helpnum==num) listOfStudents.erase(it);
        helpnum++;

    }
}
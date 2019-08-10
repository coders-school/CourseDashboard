#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include<algorithm>
#include <iterator>

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
   // std::cin>> student.nick;
    std::cout<< "\nEmail: ";
   // std::cin>> student.eMail;

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
		std::cout <<listOfStudents[i].name<< std::endl;
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
            }else
            {
                std::cout<<"Login or Password is incorect"<<std::endl<<"Try again";
            }
    }while(test==false);
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
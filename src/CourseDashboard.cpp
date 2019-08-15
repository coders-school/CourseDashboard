#include "CourseDashboard.hpp"
#include "Student.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>


CourseDashboard::CourseDashboard() {}
void CourseDashboard::addStudent(Student &user){
    std::vector<std::string> student{};
    student.push_back(user.getNick());
    student.push_back(user.getName());
    student.push_back(user.getGitHub());
    student.push_back(user.getFirecode());
 
    std::fstream baza;
    baza.open("baza.txt", std::ios::out|std::ios::app);
    for(unsigned int i = 0; i < student.size(); i++)
        baza << student[i] << std::endl;
    baza.close();
}

void CourseDashboard::removeStudent(std::string userNick){
    std::fstream baza;
    baza.open("baza.txt", std::ios::out|std::ios::in);
    
    std::string line;
    int recordsNumber=0, number;
    std::vector <std::string> userBase;
    while (getline(baza, line))
    {
        recordsNumber++;
        if(line==userNick){
            number = recordsNumber;
        }
        userBase.push_back(line);
    }
    baza.close();

    std::vector <std::string>::iterator it = userBase.begin();
    it+=(number-1);
    for(int i =0; i<4; i++)
        userBase.erase(it);

    std::fstream newBase;
    newBase.open("nowaBaza.txt", std::ios::out);
    for (unsigned int i = 0; i < userBase.size(); i++)
        newBase<< userBase[i] << std::endl;

    rename("nowaBaza.txt", "baza.txt");
    newBase.close();
}

void CourseDashboard::changeStudentData(std::string userNick){
    std::string newNick, newName, newGitHub, newFirecode;
    std::cout << "Write new student data separated with space (nick name GitHub Firecode): ";
    std::cin >> newNick >> newName >> newGitHub >> newFirecode;
    std::fstream baza;
    baza.open("baza.txt", std::ios::out|std::ios::in);
    
    std::string line;
    int recordsNumber=0, number;
    std::vector <std::string> userBase;
    while (getline(baza, line))
    {
        recordsNumber++;
        if(line==userNick){
            number = recordsNumber;
        }
        userBase.push_back(line);
    }
    baza.close();

    std::vector <std::string>::iterator it = userBase.begin();
    it+=(number-1);
    for(int i =0; i<4; i++)
        userBase.erase(it);
            
    userBase.emplace(it, newFirecode);
    userBase.emplace(it, newGitHub);
    userBase.emplace(it, newName);
    userBase.emplace(it, newNick);

    for(auto it : userBase)
        std::cout<<it<<std::endl;

    std::fstream newBase;
    newBase.open("nowaBaza.txt", std::ios::out);
    for (unsigned int i = 0; i < userBase.size(); i++)
        newBase<< userBase[i] << std::endl;

    rename("nowaBaza.txt", "baza.txt");
    newBase.close();
}

void CourseDashboard::showStudentData(std::string userNick){
    std::cout<<"User data"<<std::endl;
    
    std::fstream baza;
    baza.open("baza.txt", std::ios::out|std::ios::in);
    std::string line;
    int recordsNumber=0, number = -5;
    std::vector <std::string> userBase;

    while (getline(baza, line))
    {
        recordsNumber++;
        if(line == userNick){
            number = recordsNumber;
        }
        if(recordsNumber >= number && recordsNumber <= (number+3)){
            userBase.push_back(line);
        }
    }

    for(auto it : userBase)
        std::cout << it << " ";
    std::cout<<std::endl;
    getchar(); getchar();
    baza.close();
    
}

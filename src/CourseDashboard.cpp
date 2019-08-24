#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

CourseDashboard::CourseDashboard() {}

void CourseDashboard::showAll()
{
    for (auto & user : users_)
    {
        std::cout << user.getAllInfo();
    }
}

void CourseDashboard::createUser(const User & user)
{
    users_.emplace_back(user);
}

void CourseDashboard::deleteUserByNick(std::string nick)
{  
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });

    if (it != std::end(users_))
    {
        users_.erase(it);
    }
}

void CourseDashboard::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });
    
    if (it != std::end(users_))
    {
        std::cout << it->getAllInfo();
    }
}

void CourseDashboard::updateUser(User & user)
{
    unsigned int number;
    std::cout << user.getAllInfo();
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    std::string name, nick, group, gitHub, firecode;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        std::cin >> name;
        user.setName(name);
        break;
    case 2:
        std::cout << "Give new value to data: ";
        std::cin >> nick;
        user.setNick(nick);
        break;
    case 3:
        std::cout << "Give new value to data: ";
        std::cin >> group;
        user.setGroup(group);
        break;
    case 4:
        std::cout << "Give new value to data: ";
        std::cin >> gitHub;
        user.setGitHub(gitHub);
        break;
    case 5:
        std::cout << "Give new value to data: ";
        std::cin >> firecode;
        user.setFirecode(firecode);
        break;
    default:
        std::cout << "You gave wrong value.";
        break;
    }
}
    
void CourseDashboard::saveInFile()
{
    std::ofstream dataFile("dataFile.txt", std::ofstream::out | std::ofstream::trunc);
    if (dataFile.is_open())
    {
        for (auto & user : users_)
        {
            dataFile << user.getAllInfo();
        }
    }
}

void CourseDashboard::readFromFile()
{
    std::ifstream dataFile("dataFile.txt");
    if (dataFile.is_open())
    {
        std::string line;
        while (!dataFile.eof())
        {
            std::getline(dataFile,line);
            std::cout << line << std::endl;
        }
    }
}


void CourseDashboard::login()
{
    std::system("clear");
    bool test=false;
    do
    {

    
        
        std::string passw;
        std::string email;
        
    
        
            std::cout<<"Your Email"<<std::endl;
            std::cin>>email;
            std::cout<<std::endl<<"Your Password"<<std::endl;
            std::cin>>passw;
            std::system("clear");
                std::vector <User> ::iterator it = std::find_if (
                users_.begin(),
                users_.end(),
                [ &email,&passw,&test](const User & users_)
                {
                    if( users_.getMail() == email &&  users_.getPassword() == passw )
                    {

                        test=true;
                        return true;
                    }
                    else 
                    {          
                        return false;
                    };
                });
            if(test==true)
            {
                std::cout<<"Logged : ";
                std::cout<<it->getAllInfo();
                std::cout<<std::endl<<"Do, what you want to do"<<std::endl;
                
            }else
            {
                std::cout<<"Login or Password is incorect"<<std::endl<<"Try again"<<std::endl;
            }
          
    }while(test!=true);            
}

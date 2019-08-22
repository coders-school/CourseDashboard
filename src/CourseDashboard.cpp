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
    switch (number)
    {
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

void CourseDashboard::saveToFile()
{
    std::fstream file_DB("baza danych.txt", file_DB.in | file_DB.out);
    if(!file_DB.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {    
        for (auto & user : users_)
        {
            file_DB << user.getAllInfo();
        }
    }
    file_DB.close();
}

void CourseDashboard::loadFromFile()
{
    std::fstream file_DB("userBase.txt", file_DB.in);
    if(!file_DB.is_open())
    {
        std::cout<<"No file userBase.txt found."<<std::endl;
    }
     else
    {    
        std::string line;
        std::vector<std::string> userData{};
        while (getline(file_DB, line))
        {
            userData.push_back(line);
            if(userData.size() == 5)
            {
                User newUser(userData[0], userData[1], userData[2], userData[3], userData[4]);
                createUser(newUser);
                userData.clear();
            } 
        }
    }
    file_DB.close();
}

void CourseDashboard::loadUserFromFile()
{
    std::fstream userBase;
    userBase.open("userBase.txt", std::ios::in);
     
    if(userBase.good()==false)
    {
        std::cout<<"No file userBase.txt found."<<std::endl;
    }
    
    std::string line;
    std::vector<std::string> userData{};
    while (getline(userBase, line))
    {
        userData.push_back(line);
        if(userData.size() == 5)
        {
            User newUser(userData[0], userData[1], userData[2], userData[3], userData[4]);
            createUser(newUser);
            userData.clear();
        } 
    }
    userBase.close();
}

void CourseDashboard::writeUserToFile()
{
    std::vector<std::string> userData(5);
    std::string name, nick, group, gitHub,firecode;
    std::cout<<"Writing user to file:"<<std::endl;
    std::cout<<"- User name: ";
    std::cin>>userData[0];
    std::cout<<"- User nick: ";
    std::cin>>userData[1];
    std::cout<<"- Group: ";
    std::cin>>userData[2];
    std::cout<<"GitHub: ";
    std::cin>>userData[3];
    std::cout<<"Firecode: ";
    std::cin>>userData[4];

    User newUser(userData[0], userData[1], userData[2], userData[3], userData[4]);
    createUser(newUser);

    std::fstream userBase;
    userBase.open("userBase.txt", std::ios::out|std::ios::app);
    for(auto element : userData)
        userBase << element <<std::endl;
    userBase.close();
}

void CourseDashboard::writeUserToFile(const User & user)
{
    std::fstream userBase;
    userBase.open("userBase.txt", std::ios::out|std::ios::app);
    userBase << user.getAllInfo() <<std::endl;
    userBase.close();
}

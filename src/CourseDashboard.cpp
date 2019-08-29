#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>


CourseDashboard::CourseDashboard() = default;

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

void CourseDashboard::deleteUserByNick(const std::string& nick)
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

void CourseDashboard::retriveUserByNick(const std::string& nick)
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
    std::fstream file_DB("baza danych.txt", file_DB.in);
    if(!file_DB.is_open())
    {
        throw "Problem to open userBase.txt";
    }
    else
    {    
        std::string line;
        std::vector<std::string> usersData{};
	    std::vector<std::string> user{};
        while (getline(file_DB, line))
        {
            usersData.push_back(line);
        }
        for(auto element : usersData)
        {
            element.erase(0,2);
            for(int i=0; i<4; i++)
            {
                size_t length = element.find("|");
                user.push_back(element.substr(0,length));
                element.erase(0,(length+3));
            }
            size_t length = element.find("|");
            user.push_back(element.substr(0,length));

            User newUser(user[0], user[1], user[2], user[3], user[4]);
            createUser(newUser);
            user.clear();
        }	
    }
    file_DB.close();
}

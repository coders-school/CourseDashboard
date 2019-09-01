#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>

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

void CourseDashboard::saveUsersToFile(std::vector<User>  users)
{
    std::fstream file;
    try 
    {
    file.open("../src/UsersList.txt",std::ios::out);
    for(auto element : users)
    {
        file << element.getAllInfoToFile() << std::endl;
    }
    }
    catch (std::ifstream::failure e) 
    {
        std::cerr << "Error while opening file: " << e.what() << std::endl;
    }
}

void CourseDashboard::loadFromFile()
{
    std::ifstream file("../src/UsersList.txt");

    try
    {
        int count = 0;
        std::string name, nick, group, gitHub, firecode, line;
        while (std::getline(file, line))
        {
            switch(count%6)
            {
                case 0:
                    name = line;
                    break;
                case 1:
                    nick = line;
                    break;
                case 2:
                    group = line;
                    break;
                case 3:
                    gitHub = line;
                    break;
                case 4:
                    firecode = line;
                    User u(name, nick, group, gitHub, firecode);
                    createUser(u);
                    break;
            }
            count++;
        }
    }
    catch (std::ifstream::failure e)
    {
        std::cerr << "Error while opening file: " << e.what() << std::endl;
    }
}

std::vector<User> CourseDashboard::getVector() const
{
    return users_;
}

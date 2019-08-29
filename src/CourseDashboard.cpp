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
    usersLoginMap_[user.getEmail()] = user.getPassword();
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

void CourseDashboard::addTrainer(std::string login)
{
    trainersLoginVector_.emplace_back(login);
}

bool CourseDashboard::logInUser()
{
    std::string emailKeyword, passwordKeyword;
    std::cout << "Enter  e-mail : "; std::cin >> emailKeyword;  

    auto search = usersLoginMap_.find(emailKeyword);
    if (search != usersLoginMap_.end()) 
    {
        std::cout << "Enter Password: "; std::cin >> passwordKeyword;
        if (search -> second == passwordKeyword)
        {
            std::cout << "Login successful" << std::endl;
            return true;
        }
        else 
        {
            std::cout << "Login failure" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "User not found" << std::endl;
        return false;
    }    
}
bool CourseDashboard::logInTrainer()
{
    std::string loginKeyword;
    std::cout << "Enter login : "; std::cin >> loginKeyword;
    auto search = find (trainersLoginVector_.begin(), trainersLoginVector_.end(), loginKeyword);
    if (search != trainersLoginVector_.end()) 
    {
        std::cout << "Login successful" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Login failure" << std::endl;
        return false;
    }
    return true;
}

bool CourseDashboard::logIn()
{
    int person;
    std::cout << "1.User" << std::endl;
    std::cout << "2.Trainer" << std::endl;
    std::cout << "I am (1 or 2):  ";
    std::cin >> person;
    switch (person)
    {
    case 1:
        return logInUser();
        break;
    case 2:
        return logInTrainer();
        break;
    default:
        std::cout << "Invalid value" << std::endl;
        exit(0);
        return false;
        break;
    }
}

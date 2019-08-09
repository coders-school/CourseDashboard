#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>

CourseDashboard::CourseDashboard() {}

void CourseDashboard::showAll()
{
    for (auto & user : users_)
    {
        retriveUser(user);
    }
}

void CourseDashboard::createUser(const User & user)
{
    users_.emplace_back(user);
}

void CourseDashboard::deleteUser(const User & user)
{   
    users_.erase(users_.begin());
}

void CourseDashboard::retriveUser(const User & user)
{
    std::cout << user.getAllInfo() << std::endl;
}

// TO UPDATE
void CourseDashboard::updateUser(const User & user)
{
    unsigned int number;
    retriveUser(user);
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        //std::cin >> name_;
        break;
    case 2:
        std::cout << "Give new value to data: ";
        //std::cin >> nick_;
        break;
    case 3:
        std::cout << "Give new value to data: ";
        //std::cin >> group_;
        break;
    case 4:
        std::cout << "Give new value to data: ";
        //std::cin >> gitHub_;
        break;
    case 5:
        std::cout << "Give new value to data: ";
        //std::cin >> firecode_;
        break;
    default:
        std::cout << "You gave wrong value.";
        break;
    }
}
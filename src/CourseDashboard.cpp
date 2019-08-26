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
bool CourseDashboard::savingToFile(User & user)
{
    std::ofstream out_file{ "../ParticipantsDetails.txt", std::ios::app };
    if (!out_file)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
        out_file << user;
        out_file.close();
        return true;
}
bool CourseDashboard::readingFromFile()
{
    std::ifstream in_file{"../ParticipantsDetails.txt"};
    if (!in_file)
    {
       std::cerr << "Error" << std::endl;
       return false;
    }
    std::string text{};
    std::cout << "Reading from file ..." << std::endl;
    while (std::getline(in_file,text))
    {
        std::cout << text << std::endl;
    }
    std::cout << "=====================" << std::endl;
    in_file.close();
    return true;
}
//std::ostream operator << (std::ostream &out, const CourseDashboard &rhs)
//{

//}


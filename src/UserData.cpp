#include "UserData.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


UserData::UserData() {}

void UserData::showAll()
{
    for (auto & user : users_)
    {
        std::cout << user.getAllInfo();
    }
}

void UserData::createUser(const User & user)
{
    users_.emplace_back(user);
}

void UserData::deleteUserByNick(std::string nick)
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

void UserData::retriveUserByNick(std::string nick)
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

void UserData::updateUser(User & user, 
                        std::string name, 
                        std::string nick,
                        std::string group, 
                        std::string gitHub, 
                        std::string firecode)
{
    std::cout << user.getAllInfo();
    user.setName(name);
    user.setNick(nick);
    user.setGroup(group);
    user.setGitHub(gitHub);
    user.setFirecode(firecode);
    std::cout << "After update : " << std::endl << user.getAllInfo();
}


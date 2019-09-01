#include "UserData.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cctype>

UserData::UserData(Connect & connect) : connect_(connect) {}

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
    connect_.login(user.getEmail(), user.getPassword());
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
bool UserData::logIn( 
        std::string email, 
        std::string password)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [email] (const auto & user){ return user.getEmail() == email; });
    if (it != std::end(users_) && it->getEmail() == email && it->getPassword() == password)
    {
        if(connect_.checkIfUserIsAlreadyLoggedIn() == true)
        {
            std::cout << "Already logged in" << std::endl;
            return false;
        }
        else
        {
            connect_.login(email, password);
            return true;
        }
    }
    else   
    {
        std::cout << "Wrong email or password. Try again." << std::endl;
        return false;
    }
}

void UserData::updateUser(User & user, 
                        std::string name, 
                        std::string nick,
                        std::string group, 
                        std::string gitHub, 
                        std::string firecode,
                        std::string email,
                        std::string password)
{
    std::cout << user.getAllInfo();
    user.setName(name);
    user.setNick(nick);
    user.setGroup(group);
    user.setGitHub(gitHub);
    user.setFirecode(firecode);
    user.setEmail(email);
    user.setPassword(password);
    std::cout << "After update : " << std::endl << user.getAllInfo();
}


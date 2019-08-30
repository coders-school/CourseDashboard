#include "UserData.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cctype>

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
bool UserData::logIn( 
        std::string email, 
        std::string password)
{
    std::transform(email.begin(), email.end(), email.begin(), [] (unsigned char c) { return std::tolower(c); });
    auto it = std::find_if(std::begin(users_), std::end(users_), [email] (const auto & user){ return user.getEmail() == email; });
    if (it != std::end(users_) && it->getEmail() == email && it->getPassword() == password)
    {
        std::cout << "Hello " << it->getNick() << ". You are logged now." << std::endl;
        return it->getEmail() == email && it->getPassword() == password;
    }
    else if (email == "admin@admin.com" && password == "adminpassword")
    {
        std::cout << "Hello admin. You are logged now." << std::endl;
        return true;
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


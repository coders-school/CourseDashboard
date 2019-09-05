#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "FileHandler.hpp"
#include "Utility.hpp"


void CourseDashboard::showAll() const
{
    for (auto & user : users_)
    {
        std::cout << user.toString();
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

User* CourseDashboard::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(users_.begin(), users_.end(), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });
    if (it == users_.end())
        return nullptr;
    return &(*it);
}

void CourseDashboard::updateUser(User* userIterator,
                                 User::Group group,
                                 std::string_view name,
                                 std::string_view nick,
                                 std::string_view github,
                                 std::string_view firecode)
{
    userIterator->setGroup(group);
    if (not name.empty())
        userIterator->setName(name);
    if (not nick.empty())
        userIterator->setNick(name);
    if (not github.empty())
        userIterator->setGitHub(name);
    if (not firecode.empty())
        userIterator->setFirecode(name);
}

void CourseDashboard::loadFromFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userFromFile = fileHandler.read();
    users_  = convertToArray(userFromFile);
}

void CourseDashboard::saveToFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userVectorInJsonFormat = convertToJson(users_);
    fileHandler.write(userVectorInJsonFormat.dump());
}

void CourseDashboard::clearUserDatabase()
{
    users_.clear();
}

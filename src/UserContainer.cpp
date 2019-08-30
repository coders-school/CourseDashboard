
#include <algorithm>

#include "UserContainer.hpp"


std::stringstream UserContainer::showAll()
{
    std::stringstream output;
    for (auto & user : users_)
    {
        output << user.getAllInfo() << "\n";
    }
    return output;
}

void UserContainer::add(const User & user)
{
    users_.emplace_back(user);
}

void UserContainer::deleteUserByNick(std::string nick)
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

std::optional<User> UserContainer::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });
    
    if (it != std::end(users_))
    {
        return std::optional<User>(*it);
    }
    return std::optional<User>();
}

void UserContainer::updateUser(User & user)
{
    auto nick = user.getNick();
    auto it = std::find_if(std::begin(users_), std::end(users_), [&nick](const auto & user)
    {
        return user.getNick() == nick;
    });

    *it = user;
}


#include <algorithm>
#include <stdexcept>


#include "UserContainer.hpp"


UserContainer::UserContainer()
{}


auto UserContainer::byNick(const std::string & nick) const
{
    return [&nick](const auto & user)
    {
        return user.getNick() == nick;
    };
}

auto UserContainer::byUser(const User & user) const
{
    return [&user](const auto & dbUser)
    {
        return dbUser == user;
    };
}

std::stringstream UserContainer::showAll()
{
    std::stringstream output;
    for (auto & user : users_)
    {
        output << user.getAllInfo() << "\n";
    }
    return output;
}

void UserContainer::add(User && user)
{
    User emptyUser("", "", "", "", "");
    auto it = std::find_if(std::begin(users_), std::end(users_), byUser(user));

    if(user == emptyUser) {
        throw std::invalid_argument("Unable to add user to database. User object is empty ");
    }
    if(it != std::end(users_)) {
        throw std::invalid_argument("Unable to add user to database. User " + user.getNick() + " alrady in database ");
    }

    users_.emplace_back(std::move(user));
}

void UserContainer::deleteUserByNick(const std::string& nick)
{  
    auto it = std::find_if(std::begin(users_), std::end(users_), byNick(nick));

    if (it == std::end(users_))
    {
        throw std::invalid_argument("Unable to delete user. User " + nick + " not fund ");
    }
    users_.erase(it);
}

const User& UserContainer::getUserByNick(const std::string& nick) const
{
    auto it = std::find_if(std::begin(users_), std::end(users_), byNick(nick));

    if (it == std::end(users_))
    {
        throw std::invalid_argument("User " + nick + " not fund ");
    }
    return *it;
}

User & UserContainer::retriveUser(const User& user)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), byUser(user));
    
    if (it == std::end(users_))
    {
       throw std::invalid_argument("User " + user.getNick() + " do not exist");
    }
    return (*it);
}
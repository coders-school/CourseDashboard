#pragma once

#include <vector>

#include "User.hpp"

class UserContainer
{
private:
    std::vector<User> users_;

    auto byNick(const std::string & nick) const;
    auto byUser(const User & user) const;

public:
    UserContainer();

    std::stringstream  showAll();

    void add(User&& user);

    void deleteUserByNick(const std::string& nick);

    const User & getUserByNick(const std::string& nick) const;

    User& retriveUser(const User&);
    
};

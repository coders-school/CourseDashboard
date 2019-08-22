#pragma once

#include <vector>
#include <optional>

#include "User.hpp"

class UserContainer
{
private:
    std::vector<User> users_;
    
public:
    UserContainer() = default;

    ~UserContainer() = default;

    std::stringstream  showAll();

    void createUser(const User & user);

    void deleteUserByNick(std::string nick);

    std::optional<User> retriveUserByNick(std::string nick);
    
    void updateUser(User & user);

};

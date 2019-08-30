#pragma once
#include <iostream>
#include <vector>
#include "User.hpp"


class UserData
{
public:
    UserData();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    void retriveUserByNick(std::string nick);
    bool logIn(std::string email, std::string password);
    void updateUser(User & user, 
                    std::string name, 
                    std::string nick,
                    std::string group, 
                    std::string gitHub, 
                    std::string firecode,
                    std::string email,
                    std::string password);

protected:
    std::vector<User> users_;
};

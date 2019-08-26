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
    void updateUser(User & user);

private:
    std::vector<User> users_;
};


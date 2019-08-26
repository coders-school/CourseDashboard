#pragma once
#include <iostream>
#include <vector>
#include "User.hpp"


class UserData
{
    friend std::ostream operator << (std::ostream &out, const UserData &rhs);
public:
    UserData();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    void retriveUserByNick(std::string nick);
    void updateUser(User & user);
    bool savingToFile(User & user);
    bool readingFromFile();

private:
    std::vector<User> users_;
};

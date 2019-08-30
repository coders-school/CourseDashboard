#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
public:
    CourseDashboard();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    void retriveUserByNick(std::string nick);
    void updateUser(User & user);
    bool provideEmail(std::string emailC);
    bool providePassword(std::string password1);
    bool logIn();

private:
    std::vector<User> users_;

};

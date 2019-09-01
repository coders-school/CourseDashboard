#pragma once
#include "User.hpp"
#include <vector>
#include <map>

class CourseDashboard
{
public:
    CourseDashboard();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    void retriveUserByNick(std::string nick);
    void updateUser(User & user);
    bool logIn();
    void addTrainer(std::string login);

protected:
    std::vector<User> users_;
    std::map<std::string, std::string> usersLoginMap_;
    std::vector<std::string> trainersLoginVector_;
};

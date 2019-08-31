#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
private:
    std::vector<User> users_;
public:
    CourseDashboard();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(const std::string& nick);
    void retriveUserByNick(const std::string& nick);
    void updateUser(User & user);
    void saveToFile();
    void loadFromFile();

};

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

    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    void clearUserDatabase() { users_.clear(); };

private:
    std::vector<User> users_;

};

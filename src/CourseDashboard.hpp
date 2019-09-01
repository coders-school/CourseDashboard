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
    void saveUsersToFile(std::vector<User> users);
    void loadFromFile();
    std::vector<User> getVector() const;

private:
    std::vector<User> users_;

};

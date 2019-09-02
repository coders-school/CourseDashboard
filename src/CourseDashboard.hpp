#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
private:
    std::vector<User> users_;
public:
    CourseDashboard();
    std::basic_string<char> showAll();
    void createUser(const User & user);
    void deleteUserByNick(const std::string& nick);
    void retriveUserByNick(const std::string& nick);
    void updateUser(User & user);
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

};

#pragma once
#include "User.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

class CourseDashboard
{
public:
    CourseDashboard();
    void showAll();
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    void retriveUserByNick(std::string nick);
    void updateUser(User & user);
    void saveUsersToFile(std::string filename);
    void loadUsersFromFile(std::string filename);
    void login();
//private:
    std::vector<User> users_;

};

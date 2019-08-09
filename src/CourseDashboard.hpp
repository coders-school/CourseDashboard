#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
public:
    CourseDashboard();
    void showAll();
    void createUser(const User & user);
    void deleteUser(const User & user);
    void retriveUser(const User & user);
    void updateUser(const User & user);

private:
std::vector<User> users_;

};

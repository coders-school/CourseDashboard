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
    void updateUser(User & user);

private:
    std::vector<User> users_;

};

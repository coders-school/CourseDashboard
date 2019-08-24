#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
    friend std::ostream operator << (std::ostream &out, const CourseDashboard &rhs);

public:
    CourseDashboard();
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

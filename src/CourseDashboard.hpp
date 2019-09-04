#pragma once
#include "User.hpp"
#include <memory>
#include <vector>


class CourseDashboard
{
public:
    void showAll() const;
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    std::unique_ptr<User> retriveUserByNick(std::string nick) const;
    void updateUser(User & user);

    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    void clearUserDatabase();

private:
    std::vector<User> users_;
};

#pragma once
#include "User.hpp"
#include <vector>


class CourseDashboard
{
public:
    void showAll() const;
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    User* retriveUserByNick(std::string nick);
    void updateUser(User* userIterator,
                    User::Group group,
                    std::string_view name = "",
                    std::string_view nick = "",
                    std::string_view github = "",
                    std::string_view firecode = "");

    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    void clearUserDatabase();

private:
    std::vector<User> users_;
};

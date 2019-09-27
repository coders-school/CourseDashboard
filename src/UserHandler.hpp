#pragma once
#include "User.hpp"
#include <string>


class UserHandler
{
public:
    std::string getAll() const;
    void addUser(const User & user);
    void deleteUserByNick(std::string nick);
    User* retriveUserByNick(std::string nick);
    void updateUser(User* userIterator,
                    User::Group group,
                    std::string_view name = "",
                    std::string_view nick = "",
                    std::string_view github = "",
                    std::string_view firecode = "");
    void clearUserDatabase();
    Users getUserDatabase();

private:
    Users users_;
};

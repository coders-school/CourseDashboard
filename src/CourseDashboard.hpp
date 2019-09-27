#pragma once
#include "User.hpp"
#include <vector>
#include "UserHandler.hpp"

class CourseDashboard
{
public:
    void loadFromJson(const std::string& pathTofile);
    void saveToJson(const std::string& pathTofile);
    bool login(const std::string& email, const std::string& password) const;
    void addUser();

    UserHandler userHandler_;

private:
    std::string provideInputFromKeyboard(std::string_view valueName) const;
    User::Group provideGroupFromKeyboard() const;

};

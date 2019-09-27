#include "CourseDashboard.hpp"
#include "FileHandler.hpp"
#include "Utility.hpp"
#include "AuthenticationProvider.hpp"
#include <iostream>


void CourseDashboard::loadFromJson(const std::string& pathToFile)
{
    FileHandler fileHandler(pathToFile);
    auto userFromFile = fileHandler.read();
    userHandler_.setUserDatabase(convertToArray(userFromFile));
}

void CourseDashboard::saveToJson(const std::string& pathToFile)
{
    auto userVectorInJsonFormat = convertToJson(userHandler_.getUserDatabase());
    FileHandler fileHandler(pathToFile);
    fileHandler.write(userVectorInJsonFormat.dump());
}

bool CourseDashboard::login(const std::string& email, const std::string& password) const
{
    auto users = userHandler_.getUserDatabase();
    auto user = std::find_if(users.begin(), users.end(), [&email](auto user)
    {
        return !user.getEmail().compare(email);
    });
    if (user == users.end())
        return false;

    AuthenticationProvider authenticationProvider;
    return authenticationProvider(*user, email, password);
}

void CourseDashboard::addUser()
{
    auto name = provideInputFromKeyboard("Name");
    auto nick = provideInputFromKeyboard("Nick");
    auto group = provideGroupFromKeyboard();
    auto github = provideInputFromKeyboard("GitHub");
    auto firecode = provideInputFromKeyboard("Firecode");
    auto email = provideInputFromKeyboard("Email");
    auto password = provideInputFromKeyboard("Password");
    User newUser{name, nick, group, github, firecode, email, password};
    userHandler_.addUser(newUser);
}

std::string CourseDashboard::provideInputFromKeyboard(std::string_view valueName) const
{
    std::cout << valueName << ": ";
    std::string value{};
    std::cin >> value;
    return value;
}

User::Group CourseDashboard::provideGroupFromKeyboard() const
{
    std::cout << "Group: (0) weekend, (1) evening - please select: ";
    int value{};
    std::cin >> value;
    return static_cast<User::Group>(value);
}

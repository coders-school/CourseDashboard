#include "CourseDashboard.hpp"
#include "FileHandler.hpp"
#include "Utility.hpp"
#include "AuthenticationProvider.hpp"


void CourseDashboard::loadFromFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userFromFile = fileHandler.read();
    userHandler_.getUserDatabase()  = convertToArray(userFromFile);
}

void CourseDashboard::saveToFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userVectorInJsonFormat = convertToJson(userHandler_.getUserDatabase());
    fileHandler.write(userVectorInJsonFormat.dump());
}

bool CourseDashboard::login(const std::string& email, const std::string& password)
{
    auto byEmail = [&email](auto user) {
        return !user.getEmail().compare(email);
    };
    auto users = userHandler_.getUserDatabase();
    auto user = std::find_if(users.begin(), users.end(), byEmail);

    AuthenticationProvider authenticationProvider;

    return authenticationProvider(*user, email, password);
}

#include "CourseDashboard.hpp"
#include "FileHandler.hpp"
#include "Utility.hpp"


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


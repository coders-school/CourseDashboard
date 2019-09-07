#pragma once
#include "User.hpp"
#include <vector>
#include "UserHandler.hpp"

class CourseDashboard
{
public:
    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

private:
    UserHandler userHandler_;
};

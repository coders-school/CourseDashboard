#pragma once
#include "UserData.hpp"
#include "Login.hpp"

class CourseDashboard
{

public:
    CourseDashboard();
    bool savingToFile(User & c);
    bool readingFromFile();
};

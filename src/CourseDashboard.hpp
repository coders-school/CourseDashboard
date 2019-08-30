#pragma once
#include "UserData.hpp"


class CourseDashboard
{

public:
    CourseDashboard();
    bool savingToFile(User & c);
    bool readingFromFile();
};

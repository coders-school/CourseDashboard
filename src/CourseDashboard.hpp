#pragma once
#include "stud.hpp"

class CourseDashboard
{
public:
    CourseDashboard();
    bool isNameMissing(Student &student);
    bool isDataMissing(Student &student);
    bool isDiscordNameMissing(Student &student);
};

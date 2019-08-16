#include "CourseDashboard.hpp"
#include "stud.hpp"
#include <stdexcept>


CourseDashboard::CourseDashboard() {}

bool CourseDashboard::isNameMissing(Student &student)
{
    return (student.getName() == "");
}

bool CourseDashboard::isDiscordNameMissing(Student &student)
{
    return (student.getDiscordName() == "");
}

bool CourseDashboard::isDataMissing(Student &student)
{
    return (student.getName() == "" or
            student.getDiscordName() == "" or
            student.getGitHubLink() == "" or
            student.getGroupName() == "" or
            student.getFireCode() == "");
}

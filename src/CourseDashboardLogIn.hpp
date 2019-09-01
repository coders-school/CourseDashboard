#pragma once
#include "CourseDashboard.hpp"
#include <string>

class CourseDashboardLogIn : public CourseDashboard
{
public:
    CourseDashboardLogIn();
    ~CourseDashboardLogIn();
    bool setLoginPassword(std::string, std::string);
    std::string getLog();
    std::string getPass();
    bool logIn();

private:
    std::string log_, pass_;
};

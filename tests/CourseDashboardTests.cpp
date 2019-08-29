#include <gtest/gtest.h>
#include <string>
#include "CourseDashboard.hpp"
#include "LogIn.hpp"


TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST(LogInTests, canCreateLogInClass)
{
    LogIn logIn;
}

TEST(LogInTests, canTakeEmailAndPasswordValue)
{    
    LogIn logIn("testEmail","testPassword");
}

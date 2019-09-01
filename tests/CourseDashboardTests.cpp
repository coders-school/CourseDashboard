#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "CourseDashboardLogIn.hpp"
#include "User.hpp"

class CourseDashboardTests : public ::testing::Test
{
public:
    CourseDashboardTests()
    {
        User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "mail@com", "password");
        cdb.createUser(u1);
    }
    CourseDashboard cdb;
};

class CourseDashboardTestsLogIn : public ::testing::Test
{
public:
    CourseDashboardTestsLogIn()
    {
        User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "mail@com", "password");
        cdbLogIn.createUser(u1);
        cdbLogIn.setLoginPassword("mail@com", "password");
    }
    CourseDashboardLogIn cdbLogIn;
};

TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(CourseDashboardTests, canConstructUser)
{
    User u("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "mail@com", "password");
}

TEST_F(CourseDashboardTests, canRetriveUserByNick)
{
    cdb.retriveUserByNick("SzymonGajewski");
}

TEST_F(CourseDashboardTests, canShowAll)
{
    cdb.showAll();
}

TEST_F(CourseDashboardTestsLogIn, canLogIn)
{
    ASSERT_TRUE(cdbLogIn.logIn() == true);
}

TEST_F(CourseDashboardTestsLogIn, canNotLogIn)
{
    cdbLogIn.setLoginPassword("wrongMail", "wrongPassword");
    ASSERT_TRUE(cdbLogIn.logIn() == false);
}



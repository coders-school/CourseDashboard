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
        cdbLogIn.createUser(u1);
    }
    CourseDashboard cdb;
    CourseDashboardLogIn cdbLogIn;
};

TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(CourseDashboardTests, canConstructUser)
{
    User u;
}

TEST_F(CourseDashboardTests, canRetriveUserByNick)
{
    cdb.retriveUserByNick("SzymonGajewski");
}

TEST_F(CourseDashboardTests, canShowAll)
{
    cdb.showAll();
}

TEST_F(CourseDashboardTests, canLogIn)
{
    cdbLogIn.setLoginPassword("mail@com", "password");
    ASSERT_TRUE(cdbLogIn.logIn() == true);
}

TEST_F(CourseDashboardTests, canNotLogIn)
{
    cdbLogIn.setLoginPassword("wrongMail", "wrongPassword");
    ASSERT_FALSE(cdbLogIn.logIn() == false);
}



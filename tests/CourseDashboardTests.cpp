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
        cdbLogIn.createUser(u1);
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
    cdbLogIn.retriveUserByNick("SzymonGajewski");
}

TEST_F(CourseDashboardTests, canShowAll)
{
    cdbLogIn.showAll();
}

TEST_F(CourseDashboardTests, canLogIn)
{
    cdbLogIn.setLoginPassword("mail@com", "password");
    ASSERT_TRUE(cdbLogIn.logIn() == true);
}

TEST_F(CourseDashboardTests, canNotLogIn)
{
    cdbLogIn.setLoginPassword("wrongMail", "wrongPassword");
    ASSERT_TRUE(cdbLogIn.logIn() == false);
}



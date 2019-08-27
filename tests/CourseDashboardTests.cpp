#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "User.hpp"

class CourseDashboardTests : public ::testing::Test
{
protected:
    CourseDashboard* testCdb;
    User* testU1;

    virtual void SetUp()
    {
        testU1 = new User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "mail@com", "password");
    }

    CourseDashboardTests()
    {
        EXPECT_NE("mail", testU1->getEmail());
        EXPECT_EQ("mail@com", testU1->getEmail());
        EXPECT_TRUE(testCdb->logIn());
    }

    virtual void TearDown()
    {
        delete testU1;
        delete testCdb;
    }
};

TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}


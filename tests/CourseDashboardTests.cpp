#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "User.hpp"

class CourseDashboardTests : public ::testing::Test
{

protected:
    CourseDashboard testCdb;

    CourseDashboardTests()
    {
        User us1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
        testCdb.createUser(us1);
    }

};

TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(CourseDashboardTests, canCreateUser)
{
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewskAi");    
    ASSERT_TRUE(testCdb.createUser(u1));
}

TEST_F(CourseDashboardTests, canDeleteUser)
{
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewskAi");  
    ASSERT_TRUE(testCdb.deleteUserByNick("SzymonGajewski"));
}


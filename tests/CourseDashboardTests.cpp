#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "User.hpp"

class CourseDashboardTests : public ::testing::Test
{
protected:
    CourseDashboard testCdb;
    User testU1;

    CourseDashboardTests()
    {
        testU1 = User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
        testCdb.createUser(testU1);
        testCdb.retriveUserByNick("SzymonGajewski");
        testCdb.deleteUserByNick("SzymonGajewski");
        EXPECT_EQ("SzymonGajewski", testU1.getNick());
    }
};

TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}


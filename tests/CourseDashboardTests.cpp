#include <gtest/gtest.h>
#include "CourseDashboard.hpp"


TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST(CourseDasboardsTests, canSausageCode)
{
    
}
TEST(CourseDashboardTests, canWriteToFile)
{
    //GIVEN
    CourseDashboard testCdb;
    User testUser {"testname","testnick","testgroup","testgithub","testfirecode"};

    //WHEN
    auto result = testCdb.savingToFile(testUser);

    //THEN
    ASSERT_TRUE(result);
}
TEST(CourseDashboardTests, canReadFromFile)
{
    //GIVEN
    CourseDashboard testCdb;

    //WHEN
    auto result = testCdb.readingFromFile();

    //THEN
    ASSERT_EQ(false,result);
}

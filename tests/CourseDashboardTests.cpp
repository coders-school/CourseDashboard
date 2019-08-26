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
    UserData testUsd;
    User testUser {"testname","testnick","testgroup","testgithub","testfirecode"};

    //WHEN
    auto result = testUsd.savingToFile(testUser);

    //THEN
    ASSERT_EQ(true,result);
}
TEST(CourseDashboardTests, canReadFromFile)
{
    //GIVEN
    UserData testUsd;

    //WHEN
    auto result = testUsd.readingFromFile();

    //THEN
    ASSERT_EQ(true,result);
}

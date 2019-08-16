#include <gtest/gtest.h>
#include "CourseDashboard.hpp"


TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}
TEST(CourseDashboardTests, isNameMissing)
{
    //GIVEN
    CourseDashboard cd;
    Student test {"testname","testdiscord","testgithub","testgroup","testfirecode"};

    //WHEN
    auto result = cd.isNameMissing(test);

    //THEN
    ASSERT_EQ(false,result);
}
TEST(CourseDashboardTests, isDiscordNameMissing)
{
    //GIVEN
    CourseDashboard cd;
    Student test {"testname","","testgithub","testgroup","testfirecode"};

    //WHEN
    auto result = cd.isDiscordNameMissing(test);

    //THEN
    ASSERT_EQ(true,result);
}
TEST(CourseDashboardTests, isDataMissingFalse)
{
    //GIVEN
    CourseDashboard cd;
    Student test {"testname","testdiscord","testgithub","testgroup","testfirecode"};

    //WHEN
    auto result = cd.isDataMissing(test);

    //THEN
    ASSERT_EQ(false,result);
}
TEST(CourseDashboardTests, isDataMissingTrue)
{
    //GIVEN
    CourseDashboard cd;
    Student test {"testname","testdiscord","","testgroup","testfirecode"};

    //WHEN
    auto result = cd.isDataMissing(test);

    //THEN
    ASSERT_EQ(true,result);
}

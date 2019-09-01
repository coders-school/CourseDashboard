#include <gtest/gtest.h>
#include <string>
#include "CourseDashboard.hpp"

struct TestLogIn : public testing::Test
{
    CourseDashboard login;
};

TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(TestLogIn, EmailReturnTrue)
{
    auto result = login.provideEmail("testForEmail");

    ASSERT_TRUE(result);
}

TEST_F(TestLogIn, PasswordReturnTrue)
{
    auto result = login.providePassword("testForEmail");

    ASSERT_TRUE(result);
}


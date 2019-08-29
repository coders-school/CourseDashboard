#include <gtest/gtest.h>
#include <string>
#include "CourseDashboard.hpp"
#include "LogIn.hpp"

struct LogInTests : public testing::Test
{
    LogIn logIn;
};

TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}


TEST_F(LogInTests, canTakeEmailAndPasswordValue)
{    
    LogIn logIn("testEmail","testPassword");
}

TEST_F(LogInTests, SetEmailWithSizeGreaterThanZeroShouldBeTrue)
{
    //Act
    auto result = logIn.setEmail("testEmail");

    //Assert
    ASSERT_TRUE(result);
}

TEST_F(LogInTests, SetEmailWithSizeLowerOrEqualToZeroShoudlBeFalse)
{
    //Act
    auto result = logIn.setEmail("");

    //Assert
    ASSERT_FALSE(result);
}
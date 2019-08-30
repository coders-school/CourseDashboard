#include <gtest/gtest.h>
#include <string>
#include "CourseDashboard.hpp"
#include "Coach.hpp"
#include "User.hpp"

struct CoachClassTests : public testing::Test
{
    Coach coach;
};


TEST(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}


TEST_F(CoachClassTests, canTakeEmailAndPasswordValue)
{    
    Coach coach("testEmail","testPassword");
}

TEST_F(CoachClassTests, SetEmailWithSizeGreaterThanZeroShouldBeTrue)
{
    //Act
    auto result = coach.setEmail("testEmail");

    //Assert
    ASSERT_TRUE(result);
}

TEST_F(CoachClassTests, SetEmailWithSizeLowerOrEqualToZeroShoudlBeFalse)
{
    //Act
    auto result = coach.setEmail("");

    //Assert
    ASSERT_FALSE(result);
}

TEST_F(CoachClassTests, SetPasswordWithSizeGreaterThanZeroShouldBeTrue)
{
    //Act
    auto result = coach.setPassword("testPassword");

    //Assert
    ASSERT_TRUE(result);
}

TEST_F(CoachClassTests, SetPasswordWithSizeLowerOrEqualToZeroShouldBeFalse)
{
    //Act
    auto result = coach.setPassword("");

    //Assert
    ASSERT_FALSE(result);
}
#include <gtest/gtest.h>
#include "../src/Coach.hpp"

using namespace ::testing;

struct CoachTests : public testing::Test
{
    Coach coach = Coach("testEmail", "testPassword");
};

TEST_F(CoachTests, setEmailWithLengthBiggerThanZeroShoudlResultWithTrue)
{
    auto result = coach.setEmail("changedEmail");
    ASSERT_TRUE(result);
}

TEST_F(CoachTests, setEmailWithLengthEqualToZeroShoudlResultWithFalse)
{
    auto result = coach.setEmail("");
    ASSERT_FALSE(result);
}

TEST_F(CoachTests, setPasswordWithLengthBiggerThanZeroShouldResultWithTrue)
{
    auto result = coach.setPassword("changedPassword");
    ASSERT_TRUE(result);
}

TEST_F(CoachTests, setPasswordWithLengthEqualToZeroShoudlResultWithFalse)
{
    auto result = coach.setPassword("");
    ASSERT_FALSE(result);
}


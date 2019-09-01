#include <gtest/gtest.h>
#include "../src/CoachDataAccess.hpp"
#include "../src/Connect.hpp"
#include "../src/Coach.hpp"

using namespace ::testing;


TEST(CDAT, canCreateCoach)
{
    //Arrange
    Connect connect;
    Coach coach("testEmail", "testPassword");
    CoachDataAccess cda(connect);
    //Act
    auto result = cda.createCoach(coach);
    //Assert
    ASSERT_TRUE(result);
}

TEST(CDAT, coachLogInWhenAlreadyLoggedInShouldResultWithFalse)
{
    //Arrange
    Connect connect;
    Coach coach("testEmail", "testPassword");
    CoachDataAccess cda(connect);
    cda.createCoach(coach);
    //Act
    auto result = cda.logIn("testEmail", "testPassword");
    //Assert
    ASSERT_FALSE(result);
}

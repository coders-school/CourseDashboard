#include <gtest/gtest.h>
#include "AuthenticationProvider.hpp"
#include "User.hpp"
#include <string>


struct AuthenticationProviderTests : testing::Test
{
    AuthenticationProvider authenticator;
    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubieplacki";
    User user{"Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", email, password};
};

TEST_F(AuthenticationProviderTests, canAuthenticateEmailCaseInsensitivity)
{
    EXPECT_TRUE(authenticator.authenticate(user, email, password));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongPassword)
{
    EXPECT_FALSE(authenticator.authenticate(user, email, "lubiePLACKI"));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongEmail)
{
    EXPECT_FALSE(authenticator.authenticate(user, "szymon@gmail.com", password));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyPassword)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", email, "");
    EXPECT_FALSE(authenticator.authenticate(user, email, ""));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyEmail)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "", password);
    EXPECT_FALSE(authenticator.authenticate(user, "", password));
}

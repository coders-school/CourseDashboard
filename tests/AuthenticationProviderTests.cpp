#include <gtest/gtest.h>
#include "AuthenticationProvider.hpp"
#include "HashingPassword.hpp"
#include "User.hpp"
#include <string>


struct AuthenticationProviderTests: public testing::Test
{
    AuthenticationProvider authenticator;
    HashingPassword hash;
    std::string email = "test@gmail.com";
    std::string password = "lubieplacki";
    std::string hashedPassword = hash.hashPassword(password);
    User user{"Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", email, password};
};

TEST_F(AuthenticationProviderTests, canAuthenticateEmailCaseInsensitivity)
{
    EXPECT_TRUE(authenticator.authenticate(user, email, hashedPassword));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongPassword)
{
    std::string password = "lubiePLACKI";
    EXPECT_FALSE(authenticator.authenticate(user, email, hashedPassword));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyPassword)
{
    std::string emptyPassword = "";
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", email, emptyPassword);
    EXPECT_FALSE(authenticator.authenticate(user, email, emptyPassword));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongEmail)
{
    EXPECT_FALSE(authenticator.authenticate(user, "another@gmail.com", hashedPassword));
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyEmail)
{
    std::string emptyEmail = "";
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", emptyEmail, password);
    EXPECT_FALSE(authenticator.authenticate(user, emptyEmail, hashedPassword));
}

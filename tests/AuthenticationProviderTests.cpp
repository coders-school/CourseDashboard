#include <gtest/gtest.h>
#include "AuthenticationProvider.hpp"
#include "HashingPassword.hpp"
#include "User.hpp"
#include <string>

struct AuthenticationProviderTests: public testing::Test
{
    AuthenticationProvider authenticator;
    HashingPassword hash;
    std::string email = "alicjaliqui@gmail.com";
    std::string password = hash.hashPassword("lubieplacki");
};

TEST_F(AuthenticationProviderTests, canAuthenticate)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST_F(AuthenticationProviderTests, canAuthenticateEmailCaseInsensitivity)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongPassword)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    std::string password = "lubiePLACKI";
    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyPassword)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "");
    std::string password = "";
    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateWrongEmail)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    std::string email = "szymon@gmail.com";
    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST_F(AuthenticationProviderTests, canNotAuthenticateEmptyEmail)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "", "lubieplacki");
    AuthenticationProvider authenticator;
    std::string email = "";
    EXPECT_EQ(authenticator(user, email, password), false);
}


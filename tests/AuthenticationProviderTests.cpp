#include <gtest/gtest.h>
#include "AuthenticationProvider.hpp"
#include "User.hpp"
#include <string>


TEST(AuthenticationProviderTests, canAuthenticate)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTests, canAuthenticateEmailCaseInsensitivity)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTests, canNotAuthenticateWrongPassword)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubiePLACKI";

    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST(AuthenticationProviderTests, canNotAuthenticateEmptyPassword)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTests, canNotAuthenticateWrongEmail)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "szymon@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST(AuthenticationProviderTests, canNotAuthenticateEmptyEmail)
{
    User user("Alicja", "AJU", User::Group::evening, "alicjaliQui", "alicjaliQui", "", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), false);
}

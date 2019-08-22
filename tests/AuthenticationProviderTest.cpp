#include <gtest/gtest.h>
#include "AuthenticationProvider.hpp"
#include "User.hpp"
#include <string>


TEST(AuthenticationProviderTest, canAuthenticate)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTest, canAuthenticateEmailCaseInsensitivity)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTest, canNotAuthenticateWrongPassword)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "lubiePLACKI";

    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST(AuthenticationProviderTest, canNotAuthenticateEmptyPassword)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "");
    AuthenticationProvider authenticator;

    std::string email = "alicjaliqui@gmail.com";
    std::string password = "";

    EXPECT_EQ(authenticator(user, email, password), true);
}

TEST(AuthenticationProviderTest, canNotAuthenticateWrongEmail)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "alicjaliqui@gmail.com", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "szymon@gmail.com";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), false);
}

TEST(AuthenticationProviderTest, canNotAuthenticateEmptyEmail)
{
    User user("Alicja", "AJU", "wieczorowa", "alicjaliQui", "alicjaliQui", "", "lubieplacki");
    AuthenticationProvider authenticator;

    std::string email = "";
    std::string password = "lubieplacki";

    EXPECT_EQ(authenticator(user, email, password), false);
}

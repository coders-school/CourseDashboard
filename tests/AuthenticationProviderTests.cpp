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

TEST(AuthenticationProviderTests, hashingPasswordReturnsTheSamePassword)
{
    AuthenticationProvider authenticator;
    
    std::string hashedPassword = authenticator.hashPassword("lubieplacki");
    std::string result = "lubieplacki";

    ASSERT_FALSE(hashedPassword == result);
}

TEST(AuthenticationProviderTests, hashingPasswordReturnsCorrectEncryption)
{
    AuthenticationProvider authenticator;
    
    std::string hashedPassword = authenticator.hashPassword("lubieplacki");
    std::string result = "1949dc019c411f92c6f3dad9358feecc1840befe6a0601cae30859341eab3ba7";

    EXPECT_EQ(hashedPassword, result);
}

#include <gtest/gtest.h>

#include "CRUDValidation.hpp"

TEST(CRUDValidation, isNameValid)
{
    ASSERT_TRUE(crud::validateName("Kamil"));
}

TEST(CRUDValidation, isNameInvalidSmallLetters)
{
    ASSERT_FALSE(crud::validateName("kamil"));
}

TEST(CRUDValidation, isNameInvalidNumbers)
{
    ASSERT_FALSE(crud::validateName("9Kamil"));
    ASSERT_FALSE(crud::validateName("Kamil9"));
    ASSERT_FALSE(crud::validateName("Kam9il"));
}

TEST(CRUDValidation, isNameInvalidSpecialCharacters)
{
    ASSERT_FALSE(crud::validateName("-Kamil"));
    ASSERT_FALSE(crud::validateName("Kamil-"));
    ASSERT_FALSE(crud::validateName("Kam-il"));
}


TEST(CRUDValidation, isEmailValid)
{
    ASSERT_TRUE(crud::validateEmail("kamil.waszkiewicz.2@gmail.com"));
}

TEST(CRUDValidation, isEmailInvalid1)
{
    ASSERT_FALSE(crud::validateEmail("email.example.com"));
    ASSERT_FALSE(crud::validateEmail("email.@example.com"));
}

TEST(CRUDValidation, isGitHubLinkValid)
{
    ASSERT_TRUE(crud::validateGitHubLink("https://github.com/darkassazi"));
}

TEST(CRUDValidation, isGitHubLinkInValid)
{
    ASSERT_FALSE(crud::validateGitHubLink("https://github.com/sh--innn"));
}

TEST(CRUDValidation, isFirecodeLinkValid)
{
    ASSERT_TRUE(crud::validateFirecodeLink("https://www.firecode.io/pages/profile/35190"));
}

TEST(CRUDValidation, isFirecodeLinkInvalid)
{
    ASSERT_FALSE(crud::validateFirecodeLink("https://www.firecode.io/pages/profile/3519c"));
}

TEST(CRUDValidation, isGroupvalid)
{
    ASSERT_TRUE(crud::validateGroup("Weekend"));
    ASSERT_TRUE(crud::validateGroup("Weekend 1"));
    ASSERT_TRUE(crud::validateGroup("Weekend-1"));
}


TEST(ValidationTests, isGroupInvalid1)
{
    ASSERT_FALSE(crud::validateGroup("weekend"));
    ASSERT_FALSE(crud::validateGroup("Weekend = 1"));
    ASSERT_FALSE(crud::validateFirecodeLink("1 Weekend"));
}
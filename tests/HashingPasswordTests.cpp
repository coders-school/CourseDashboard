#include <gtest/gtest.h>
#include "HashingPassword.hpp"
#include "User.hpp"
#include <string>

struct HashingPasswordTests: public testing::Test
{
    HashingPassword hash;
    std::string hashedPassword = hash.hashPassword("lubieplacki");
};

TEST_F(HashingPasswordTests, hashingPasswordReturnsTheSamePassword)
{
    std::string result = "lubieplacki";
    ASSERT_FALSE(hashedPassword == result);
}

TEST_F(HashingPasswordTests, hashingPasswordReturnsCorrectEncryption)
{
    std::string result = "1949dc019c411f92c6f3dad9358feecc1840befe6a0601cae30859341eab3ba7";
    EXPECT_EQ(hashedPassword, result);
}

TEST_F(HashingPasswordTests, hashingUppercasePasswordReturnsInorrectEncryption)
{
    std::string hashedPassword = hash.hashPassword("LUBIEplacki");
    std::string result = "1949dc019c411f92c6f3dad9358feecc1840befe6a0601cae30859341eab3ba7";
    ASSERT_FALSE(hashedPassword == result);
}
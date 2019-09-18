#include <gtest/gtest.h>
#include <string>
#include "../src/PasswordHashingProvider.hpp"

class PasswordHashingProviderTests : public ::testing::Test {
public:
    bool checkIfStringContainsSubstring(const std::string& parentString, const std::string& subString) {
        return std::string::npos != parentString.find(subString);
    }

    const unsigned defaultSaltLength = 16;
    const unsigned defaultHashLength = 16;
    const std::string defaultSalt{"1234567890123456"};
    const std::string defaultPassword{"trustnoone"};  
};

TEST_F(PasswordHashingProviderTests, WhenUsingDefaultConstructorSaltLengthIsEqualTo16)
{
    const unsigned expectedSaltLength = 16;
    PasswordHashingProvider h1 = PasswordHashingProvider();
        
    std::string salt1 = h1.generateSalt();
    
    ASSERT_EQ(salt1.length(), expectedSaltLength);
}

TEST_F(PasswordHashingProviderTests, CanGenerateSaltWithGivenLength)
{
    const unsigned SaltLength = 24;
    PasswordHashingProvider h1(SaltLength, defaultHashLength);
    
    std::string salt1 = h1.generateSalt();
    
    ASSERT_EQ(salt1.length(), SaltLength);
}

TEST_F(PasswordHashingProviderTests, CannotGenerateSaltShorterThan8)
{
    const unsigned givenSaltLength = 4;
    const unsigned expectedSaltLength = 8;
    PasswordHashingProvider h1(givenSaltLength, defaultHashLength);
    
    std::string salt1 = h1.generateSalt();
    
    ASSERT_EQ(salt1.length(), expectedSaltLength);
}

TEST_F(PasswordHashingProviderTests, CannotGenerateSaltLongerThan32)
{
    const unsigned givenSaltLength = 33;
    const unsigned expectedSaltLength = 32;
    PasswordHashingProvider h1(givenSaltLength, defaultSaltLength);
    
    std::string salt1 = h1.generateSalt();
    
    ASSERT_EQ(salt1.length(), expectedSaltLength);
}

TEST_F(PasswordHashingProviderTests, CanGenerateDifferentSaltsDuringFirstUseFromTwoInstances)
{
    PasswordHashingProvider h1(defaultSaltLength, defaultHashLength);
    PasswordHashingProvider h2(defaultSaltLength, defaultHashLength);
    
    std::string salt1 = h1.generateSalt();
    std::string salt2 = h2.generateSalt();

    ASSERT_NE(salt1, salt2);
}

TEST_F(PasswordHashingProviderTests, CanGenerateDifferentSaltsFromOneInstance)
{
    PasswordHashingProvider h1(defaultSaltLength, defaultHashLength);
        
    std::string salt1 = h1.generateSalt();
    std::string salt2 = h1.generateSalt();

    ASSERT_NE(salt1, salt2);
}

TEST_F(PasswordHashingProviderTests, WhenUsingDefaultConstructorHashLengthIsEqualTo16)
{
    const unsigned givenHashLength = 16;
    const unsigned expectedHashLength = 2*givenHashLength;
    PasswordHashingProvider h1 = PasswordHashingProvider();
        
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), expectedHashLength);
}

TEST_F(PasswordHashingProviderTests, CanGenerateHashWithGivenLength)
{
    const unsigned givenHashLength = 32;
    const unsigned expectedHashLength = 2*givenHashLength;
    PasswordHashingProvider h1(defaultSaltLength, givenHashLength);
        
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), expectedHashLength);
}

TEST_F(PasswordHashingProviderTests, CannotGenerateHashShorterThan8)
{
    const unsigned givenHashLength = 4;
    const unsigned expectedHashLength = 2*8;
    PasswordHashingProvider h1(defaultSaltLength, givenHashLength);
        
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), expectedHashLength);
}

TEST_F(PasswordHashingProviderTests, CannotGenerateHashLongerThan64)
{
    const unsigned givenHashLength = 128;
    const unsigned expectedHashLength = 2*64;
    PasswordHashingProvider h1(defaultSaltLength, givenHashLength);
        
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), expectedHashLength);
}

TEST_F(PasswordHashingProviderTests, CanConstructClassInstanceWithCopyConstructor)
{
    const unsigned givenHashLength = 64;
    PasswordHashingProvider h1(defaultSaltLength, givenHashLength);
    
    PasswordHashingProvider h2(h1);
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    std::string hash2 = h2.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), hash2.length());
    ASSERT_EQ(hash1, hash2);
}

TEST_F(PasswordHashingProviderTests, CanConstructClassInstanceWithCopyAssignmentOperator)
{
    const unsigned givenHashLength = 64;
    PasswordHashingProvider h1(defaultSaltLength, givenHashLength);
    
    PasswordHashingProvider h2 = h1;
    std::string hash1 = h1.generateHash(defaultSalt, defaultPassword);
    std::string hash2 = h2.generateHash(defaultSalt, defaultPassword);
    
    ASSERT_EQ(hash1.length(), hash2.length());
    ASSERT_EQ(hash1, hash2);
}

TEST_F(PasswordHashingProviderTests, TwoDifferentPasswordsWithSameSaltGeneratesDifferentHash)
{
    PasswordHashingProvider h1(defaultSaltLength, defaultHashLength);
    std::string testPassphrase1{"AlaMaKota"};
    std::string testPassphrase2{"AlaNieMaKota"};
    
    std::string hash1 = h1.generateHash(defaultSalt, testPassphrase1);
    std::string hash2 = h1.generateHash(defaultSalt, testPassphrase2);
    
    ASSERT_NE(hash1, hash2);
}

TEST_F(PasswordHashingProviderTests, TwoDifferentSaltsWithSamePasswordGeneratesDifferentHash)
{
    PasswordHashingProvider h1(defaultSaltLength, defaultHashLength);
    std::string testSalt1{h1.generateSalt()};
    std::string testSalt2{h1.generateSalt()};
    
    std::string hash1 = h1.generateHash(testSalt1, defaultPassword);
    std::string hash2 = h1.generateHash(testSalt2, defaultPassword);
    
    ASSERT_NE(hash1, hash2);
}

TEST_F(PasswordHashingProviderTests, GeneratedHashDoesntContainPlainPassword)
{
    PasswordHashingProvider h1(defaultSaltLength, defaultHashLength);
    std::string givenSalt{""};
    std::string givenPassphrase{"primo"};
    bool doesHashContainPlainPassword{};
        
    std::string hash1 = h1.generateHash(givenSalt, givenPassphrase);
    doesHashContainPlainPassword = checkIfStringContainsSubstring(hash1, givenPassphrase);
    
    ASSERT_FALSE(doesHashContainPlainPassword);
}

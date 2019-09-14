#pragma once
#include <string>

class PasswordHashingProvider {
public:
    PasswordHashingProvider();
    PasswordHashingProvider(unsigned pwdSaltLength, unsigned pwdHashLength);
    PasswordHashingProvider(const PasswordHashingProvider& other);
    ~PasswordHashingProvider();
    PasswordHashingProvider& operator= (const PasswordHashingProvider& other);

    std::string generateSalt();
    std::string generateHash(const std::string& passwordSalt, const std::string& passwordPhrase);

private:
    void checkAndCorrectInitialValues(unsigned& saltLength, unsigned& hashLength);
    std::string convertToString(const uint8_t* input, const unsigned& length);

    unsigned passwordSaltLength;
    unsigned passwordHashLength;  
    static const unsigned minSaltLength = 8;
    static const unsigned maxSaltLength = 32;
    static const unsigned minHashLength = 8;
    static const unsigned maxHashLength = 64;
};

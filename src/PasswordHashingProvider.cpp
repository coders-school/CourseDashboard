#include "./PasswordHashingProvider.hpp"
#include "../external/argon2/include/argon2.h"
#include <pthread.h>
#include <iomanip>
#include <random>
#include <memory>

PasswordHashingProvider::PasswordHashingProvider() : 
    passwordSaltLength(16), passwordHashLength(16) {
}

PasswordHashingProvider::PasswordHashingProvider(unsigned pwdSaltLength, unsigned pwdHashLength) :
    passwordSaltLength(pwdSaltLength), passwordHashLength(pwdHashLength) {
    checkAndCorrectInitialValues(passwordSaltLength, passwordHashLength);
}

PasswordHashingProvider::PasswordHashingProvider(const PasswordHashingProvider& other) :
    passwordSaltLength(other.passwordSaltLength),
    passwordHashLength(other.passwordHashLength) {
}

PasswordHashingProvider::~PasswordHashingProvider() {
}

PasswordHashingProvider& PasswordHashingProvider::operator= (const PasswordHashingProvider& other) {
    return *this = PasswordHashingProvider(other);
}

std::string PasswordHashingProvider::generateSalt() {
    std::random_device randDev;
    std::mt19937 randEng(randDev());
    std::uniform_int_distribution<unsigned> uIDistr(0,9);  
    std::stringstream stringStream{};
    for (unsigned it = 0; it < passwordSaltLength; ++it) 
        stringStream << uIDistr(randEng);
    return stringStream.str();
}

std::string PasswordHashingProvider::generateHash(const std::string& passwordSalt, const std::string& passwordPhrase) {
    std::unique_ptr<uint8_t> temporaryHash(new uint8_t[passwordHashLength]);
    argon2d_hash_raw(
        1, (1<<16), 1, passwordPhrase.c_str(), passwordPhrase.length(), 
        passwordSalt.c_str(), passwordSalt.length(), temporaryHash.get(), passwordHashLength);
    return convertToString(temporaryHash.get(), passwordHashLength);
}

void PasswordHashingProvider::checkAndCorrectInitialValues(unsigned& saltLength, unsigned& hashLength) {
    if (saltLength < minSaltLength)
        saltLength = minSaltLength;
    if (saltLength > maxSaltLength)
        saltLength = maxSaltLength;
    if (hashLength < minHashLength)
        hashLength = minHashLength;
    if (hashLength > maxHashLength)
        hashLength = maxHashLength;
}

std::string PasswordHashingProvider::convertToString(const uint8_t* input, const unsigned& length) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned i=1; i<=length; ++i)
        ss << std::setw(2) << static_cast<int>(input[i]);
    return ss.str();
}

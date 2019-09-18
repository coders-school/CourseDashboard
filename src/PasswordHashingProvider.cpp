#include "./PasswordHashingProvider.hpp"
#include "../external/argon2/include/argon2.h"
#include <pthread.h>
#include <iomanip>
#include <random>
#include <memory>
#include <algorithm>
#include <iostream>
#include <sstream>

PasswordHashingProvider::PasswordHashingProvider() : 
    PasswordHashingProvider(16, 16)
{}

PasswordHashingProvider::PasswordHashingProvider(unsigned pwdSaltLength, unsigned pwdHashLength) :
    passwordSaltLength(pwdSaltLength), passwordHashLength(pwdHashLength) {
    checkAndCorrectInitialValues(pwdSaltLength, pwdHashLength);
}

PasswordHashingProvider::~PasswordHashingProvider() {
}

void PasswordHashingProvider::printSaltAndHashLength() const {
    std::cout << "PasswordHashingProvider instance:\n";
    std::cout << "  salt length:" << passwordSaltLength << '\n';
    std::cout << "  hash length:" << passwordHashLength << '\n';
    std::cout << "  iterations:" << iterations << '\n';
    std::cout << "  memory cost:" << memoryCost << '\n';
    std::cout << "  threads:" << threads << '\n';
}

std::string PasswordHashingProvider::generateSalt() const {
    std::random_device randDev;
    std::mt19937 randEng(randDev());
    std::uniform_int_distribution<unsigned> uIDistr(0,9);  
    std::stringstream stringStream{};
    for (unsigned it = 0; it < passwordSaltLength; ++it) 
        stringStream << uIDistr(randEng);
    return stringStream.str();
}

std::string PasswordHashingProvider::generateHash(const std::string& passwordSalt, const std::string& passwordPhrase) const {
    std::unique_ptr<uint8_t> temporaryHash(new uint8_t[passwordHashLength]);
    argon2d_hash_raw(
        iterations, memoryCost, threads, passwordPhrase.c_str(), passwordPhrase.length(), 
        passwordSalt.c_str(), passwordSalt.length(), temporaryHash.get(), passwordHashLength);
    return convertToString(temporaryHash.get(), passwordHashLength);
}

void PasswordHashingProvider::checkAndCorrectInitialValues(const unsigned& saltLength, const unsigned& hashLength) {
    passwordSaltLength = std::max(passwordSaltLength, static_cast<unsigned>(PasswordHashingProvider::minSaltLength));
    passwordSaltLength = std::min(passwordSaltLength, static_cast<unsigned>(PasswordHashingProvider::maxSaltLength));
    passwordHashLength = std::max(passwordHashLength, static_cast<unsigned>(PasswordHashingProvider::minHashLength));
    passwordHashLength = std::min(passwordHashLength, static_cast<unsigned>(PasswordHashingProvider::maxHashLength));
}

std::string PasswordHashingProvider::convertToString(const uint8_t* input, const unsigned& length) const {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned i=1; i<=length; ++i)
        ss << std::setw(2) << static_cast<int>(input[i]);
    return ss.str();
}

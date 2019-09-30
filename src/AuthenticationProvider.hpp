#pragma once
#include <string>
#include "User.hpp"

class AuthenticationProvider
{
    bool validateEmail(const User & user, const std::string & email);
    bool validatePassword(const User & user, const std::string & password);
    std::string hashedPassword_;
    
public:
    bool authenticate(
        const User & user,
        const std::string & email,
        const std::string & password);

    std::string hashPassword(std::string p);
};

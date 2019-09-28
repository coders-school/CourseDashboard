#pragma once
#include <string>
#include "User.hpp"

class AuthenticationProvider
{
    static bool validateEmail(const User & user, const std::string & email);
    static bool validatePassword(const User & user, const std::string & password);

public:
    bool operator()(
        const User & user,
        const std::string & email,
        const std::string & password);
};

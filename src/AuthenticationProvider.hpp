#pragma once
#include <string>
#include "User.hpp"

class AuthenticationProvider {
public:
    bool operator()(
        const User & user,
        const std::string & email,
        const std::string & password);
};

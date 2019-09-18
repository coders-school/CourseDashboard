#include "AuthenticationProvider.hpp"
#include <algorithm>
#include <iostream>

bool AuthenticationProvider::operator()(
    const User & user,
    const std::string & email,
    const std::string & password)
{
    return (user.validateEmail(email) && user.validatePassword(password));
}

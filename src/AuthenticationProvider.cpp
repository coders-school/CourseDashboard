#include "AuthenticationProvider.hpp"
#include <algorithm>
#include <iostream>

bool AuthenticationProvider::authenticate(
    const User & user,
    const std::string & email,
    const std::string & password)
{
    return (validateEmail(user, email) && validatePassword(user, password));
}


bool AuthenticationProvider::validateEmail(
    const User & user,
    const std::string & email)
{
    std::string user_email = user.getEmail();
    
    if (not email.empty() && (email.size() == user_email.size()))
    {
        for (unsigned int i=0; i<email.size(); i++)
            if (tolower(email[i]) != tolower(user_email[i]))
                return false;            
    }
    else
        return false;

    return true;
}

bool AuthenticationProvider::validatePassword(
    const User & user,
    const std::string & password)
{
    if (password.empty())
        return false;
    return (user.getPassword() == password);
}

 std::string AuthenticationProvider::hashPassword(std::string p)
 {
     std::string hashedPassword_ = picosha2::hash256_hex_string(p);
     return hashedPassword_;
 }

                                          
#include "AuthenticationProvider.hpp"
#include <algorithm>
#include <iostream>

bool AuthenticationProvider::operator()(
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
    
    if(!email.empty() && (email.size() == user_email.size())) {
        for(size_t i=0; i<email.size(); i++) {
            if(tolower(email[i]) != tolower(user_email[i]))
                return false;            
        }
    } else {
        return false;
    }

    return true;
}

bool AuthenticationProvider::validatePassword(
    const User & user,
    const std::string & password)
{
    return (user.getPassword() == password);
}
                                          
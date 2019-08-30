#include "LogIn.hpp"
#include <string>

LogIn::LogIn(const std::string email, const std::string password)
            :email_(email),
             password_(password)
             {}

bool LogIn::setEmail(const std::string email)
{
    if(email.size() > 0)
    {
        email_= email;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool LogIn::setPassword(const std::string password)
{
    if(password.size() > 0)
    {
        password_ = password;
        return true;
    }
    else
    {
        return false;
    }
    
}

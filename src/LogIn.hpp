#pragma once
#include <string>

class LogIn
{
public:
    LogIn(const std::string email, const std::string password);
    LogIn() = default;
    
    bool setEmail(const std::string email);
    bool setPassword(const std::string password);


private:
    std::string email_;
    std::string password_;
};
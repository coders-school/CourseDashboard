#pragma once
#include <string>

class Coach
{
public:
    Coach(const std::string email, const std::string password);
    Coach() = default;
    
    bool setEmail(const std::string email);
    bool setPassword(const std::string password);


private:
    std::string email_;
    std::string password_;
};
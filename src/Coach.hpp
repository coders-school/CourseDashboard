#pragma once
#include <string>


class Coach
{
public:
    Coach(std::string email, std::string password);
    bool setEmail(const std::string email);
    bool setPassword(const std::string password);
    std::string getEmail() const;
    std::string getPassword() const;

private:
    std::string email_;
    std::string password_;
};
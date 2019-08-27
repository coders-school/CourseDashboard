#pragma once
#include <iostream>
#include "User.hpp"

class Login
{
    public:
        bool LogInToTheApplication( User & user, std::string email, std::string password);
    
};
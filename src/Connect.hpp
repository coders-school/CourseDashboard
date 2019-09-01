#pragma once
#include <string>
#include <iostream>

class Connect
{
public:
    
    bool login(const std::string& ,const std::string& ) 
    {
        std::cout << "Access granted" << std::endl;
        isLoggedIn = true;
        return true;
    }

    bool checkIfUserIsAlreadyLoggedIn()
    {
        return isLoggedIn;
    }

    bool logout() 
    {
        std::cout << "Logout" << std::endl;
        isLoggedIn = false;
        return true;
    }

private:
    bool isLoggedIn = true;
};
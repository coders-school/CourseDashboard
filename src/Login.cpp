#include "Login.hpp"


    bool Login::LogInToTheApplication(
        User & user, 
        std::string email, 
        std::string password)
    {        
        if(email == user.getEmail() && password == user.getPassword())
        {
            std::cout << "You are logged now." << std::endl;
            return true;
        }
        else
        {
            std::cout << "Invalid email or password." << std::endl;
            return false;
        }
    }

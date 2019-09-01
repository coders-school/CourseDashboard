#include "CourseDashboardLogIn.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>

CourseDashboardLogIn::CourseDashboardLogIn()
{}

CourseDashboardLogIn::~CourseDashboardLogIn()
{}

std::string CourseDashboardLogIn::getLog()
{
    return log_;
}

std::string CourseDashboardLogIn::getPass()
{
    return pass_;
}

bool CourseDashboardLogIn::setLoginPassword(std::string login, std::string password)
{
    log_ = login;
    pass_ = password;
}

bool CourseDashboardLogIn::logIn()
{
    std::string loginKeyword = this->getLog();

    auto searchTrainer = std::find(trainersLoginVector_.begin(), 
                                   trainersLoginVector_.end(),
                                   loginKeyword);

    if (searchTrainer != trainersLoginVector_.end())
    {
        return true;
    }
    else
    {
        auto searchUser = usersLoginMap_.find(loginKeyword);
        if (searchUser != usersLoginMap_.end()) 
        {
            std::string passwordKeyword = this->getPass();
            return ((searchUser->second) == passwordKeyword);
        }
        else
        {
            return false;
        }
    }    
}


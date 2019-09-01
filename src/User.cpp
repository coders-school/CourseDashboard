#include "User.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
User::User(
           const std::string & name,
           const std::string & nick,
           const std::string & group,
           const std::string & gitHub,
           const std::string & firecode,
           const std::string & email,
           const std::string & password)
    : name_(name)
    , nick_(nick)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
    , email_(email)
    , password_(password)
{}

std::string User::getAllInfo() const
{
    std::stringstream ss;
    ss<<std::left;   
    ss<<std::setw(1) << "1." << name_ << "|";
    ss<<std::setw(1) << "2." << nick_ << "|";
    ss<<std::setw(1) << "3." << group_ << "|";
    ss<<std::setw(1) << "4." << gitHub_ << "|";
    ss<<std::setw(1) << "5." << firecode_ << "|";
    ss<<std::setw(1) << "6." << email_ << "|";
    ss<<std::setw(1) << "7." << "******" << "|";
    ss<<std::endl;
    return ss.str();
}
bool User::setName(std::string name)
{
    if(name.size() > 0)
    {
        name_ = name;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool User::setNick(std::string nick)
{
    if(nick.size() > 0)
    {
        nick_ = nick;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool User::setGroup(std::string group)
{
    if(group.size() > 0)
    {
        group_ = group;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool User::setGitHub(std::string gitHub)
{
    if(gitHub.size() > 0)
    {
        gitHub_ = gitHub;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool User::setFirecode(std::string firecode)
{
    if(firecode.size() > 0)
    {
        firecode_ = firecode;
        return true;
    }
    else
    {
        return false;
    }
    
}
std::string User::getNick() const 
{
    return nick_;
}
std::string User::getEmail() const 
{
    return email_;
}
std::string User::getPassword() const 
{
    return password_;
}
std::ostream &operator << (std::ostream &out, const User &c)
 {
     out << c.name_ << " " << c.nick_ << " " << c.group_ << " "  << c.gitHub_ << " " << c.firecode_ << " " << c.email_ << " " << "******" << std::endl;
     return out;
 }


bool User::setEmail(std::string email)
{
    if(email.size() > 0)
    {
        email_ = email;
        return true;
    }
    else
    {
        return false;
    }
}

bool User::setPassword(std::string password)
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

//int User::tryToLogin(std::string email, std::string password)
//{
//    if(email != email_ or password != password_)
//    {
//        std::cout << "Fail :)" << std::endl;
//        return -1;
//    }
//    else
//    {
//        if(connect_.checkIfUserIsAlreadyLoggedIn() == true)
//        {
//            std::cout << "Already logged in" << std::endl;
//            return -1;
//        }
//        else
//        {
//            connect_.login(email,password);
//            return 1;    
//        }
//    }
//}
//
//int User::tryToLogout()
//{
//    if(connect_.checkIfUserIsAlreadyLoggedIn() == false)
//    {
//        std::cout << "Already logged out" << std::endl;
//        return -1;
//    }
//    else
//    {
//        connect_.logout();
//    }
//}
//
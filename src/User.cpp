#include "User.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
User::User(const std::string & name,
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
    ,password_(password)
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
void User::setName(std::string name)
{
    name_ = name;
}
void User::setNick(std::string nick)
{
    nick_ = nick;
}
void User::setGroup(std::string group)
{
    group_ = group;
}
void User::setGitHub(std::string gitHub)
{
    gitHub_ = gitHub;
}
void User::setFirecode(std::string firecode)
{
    firecode_ = firecode;
}
void User::setEmail(std::string email)
{
    std::transform(email.begin(), email.end(), email.begin(),
    [](unsigned char c){ return std::tolower(c); });
    email_ = email;
}
void User::setPassword(std::string password)
{
    password_ = password;
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


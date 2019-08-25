#include "User.hpp"
#include <iostream>

User::User(const std::string & name,
           const std::string & nick,
           const std::string & password,
           const std::string & mail,
           const std::string & group,
           const std::string & gitHub,
           const std::string & firecode)
    : name_(name)
    , nick_(nick)
    , password_(password)
    , mail_(mail)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
{}

std::string User::getAllInfo() const
{
    std::stringstream ss;
    ss<<std::left;   
    ss<<std::setw(1) << "1." << name_ << "|";
    ss<<std::setw(1) << "2." << nick_ << "|";
    ss<<std::setw(1) << "2." << password_ << "|";
    ss<<std::setw(1) << "2." << mail_ << "|";
    ss<<std::setw(1) << "3." << group_ << "|";
    ss<<std::setw(1) << "4." << gitHub_ << "|";
    ss<<std::setw(1) << "5." << firecode_ << "|";
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
void User::setPassword(std::string password)
{
    password_=password;
}
void User::setMail(std::string mail)
{
    mail_=mail;
}

std::string User::getName() const
{
    return name_;
}
std::string User::getNick()  const
{
    return nick_;
}
std::string User::getPassword()  const
{
    return password_;
}
std::string User::getMail()  const
{
    return mail_;
}
std::string User::getGroup()  const
{
    return group_;
}
std::string User::getGitHub()  const
{
    return gitHub_;
}
std::string User::getFirecode()  const
{
    return firecode_;
}

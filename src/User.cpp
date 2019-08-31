#include "User.hpp"
#include <iostream>



User::User(const std::string & name,
           const std::string & nick,
           const std::string & group,
           const std::string & gitHub,
           const std::string & firecode)
    : name_(name)
    , nick_(nick)
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

std::string User::getNick() const 
{
    return nick_;
}

std::string User::getName() const
{
    return name_;
}

bool operator==(const User& lhs, const User& rhs)
{
    return !(lhs.name_.compare(rhs.name_) or
             lhs.nick_.compare(rhs.nick_) or
             lhs.group_.compare(rhs.group_) or
             lhs.gitHub_.compare(rhs.gitHub_) or
             lhs.firecode_.compare(rhs.firecode_));
}

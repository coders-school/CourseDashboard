#include "User.hpp"
#include <iostream>

User::User(const std::string name,
           const std::string nick,
           const std::string group,
           const std::string gitHub,
           const std::string firecode)
    : name_(name)
    , nick_(nick)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
{}

std::string User::getAllInfo() const
{
    std::string output;
    output.append("1.").append(name_).append("|");
    output.append("2.").append(nick_).append("|");
    output.append("3.").append(group_).append("|");
    output.append("4.").append(gitHub_).append("|");
    output.append("5.").append(firecode_).append("|");
    output.append("\n");
    return output;
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
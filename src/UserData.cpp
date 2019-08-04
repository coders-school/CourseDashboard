#include <iostream>
#include <string>
#include "UserData.hpp"

UserData::UserData(std::string name, std::string nick, std::string firecodeLink, std::string githubLink) 
    : name_(name)
    , nick_(nick)
    , firecodeLink_(firecodeLink)
    , githubLink_(githubLink)
    {}

void UserData::setName(std::string name)
{
    name_ = name;
}

std::string UserData::getName() const
{
    return name_;
}

void UserData::setNick(std::string nick) 
{
    nick_ = nick;
}

std::string UserData::getNick() const
{
    return nick_;
}

void UserData::setFirecodeLink(std::string firecodeLink)
{
    firecodeLink_ = firecodeLink;
}

std::string UserData::getFirecodeLink() const
{
    return firecodeLink_;
}

void UserData::setGithubLink(std::string githubLink)
{
    githubLink_ = githubLink;
}

std::string UserData::getGithubLink() const
{
    return githubLink_;
}

void UserData::setGroup(Group group)
{
    group_ = group;
}

Group UserData::getGroup() const
{
    return group_;
}

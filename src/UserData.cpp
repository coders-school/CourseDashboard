#include <iostream>
#include <string>
#include "UserData.hpp"

void UserData::setName(std::string name_)
{
    name = name_;
}

const std::string UserData::getName()
{
    return name;
}

void UserData::setNick(std::string nick_)
{
    nick = nick_;
}

const std::string UserData::getNick()
{
    return nick;
}

void UserData::setFirecodeLink(std::string firecodeLink_)
{
    firecodeLink = firecodeLink_;
}

const std::string UserData::getFirecodeLink()
{
    return firecodeLink;
}

void UserData::setGithubLink(std::string githubLink_)
{
    githubLink = githubLink_;
}

const std::string UserData::getGithubLink()
{
    return githubLink;
}

#include "Coders.hpp"
#include <iostream>
#include <string>

Coders::Coders(std::string userName_, std::string discordNickname_, std::string githubLink_,
    std::string firecodeLink_, std::string group_)
    :userName(userName_)
    ,discordNickname(discordNickname_)
    ,githubLink(githubLink_)
    ,firecodeLink(firecodeLink_)
    ,group(group_){}

std::string Coders::toString()
{
    std::string resultPrint = "";
    resultPrint += userName;
    resultPrint += " "+ discordNickname;
    resultPrint += " "+ githubLink;
    resultPrint += " "+ firecodeLink + '\n';
    resultPrint += " "+ group + '\n';
    return resultPrint;
}
/*
void Coders::printName() 
{
    std::cout << userName;
}

void Coders::printDiscordNickname() 
{
    std::cout << discordNickname;
}
void Coders::printGithubLink() 
{
    std::cout << githubLink;
}
void Coders::printFirecodeLink() 
{
    std::cout << firecodeLink; 
}
void Coders::printGroup() 
{
    std::cout << group;
}

void Coders::insertName(std::string tmpName)
{
    userName = tmpName;
}
void Coders::insertDiscordNickname(std::string tmpDiscord) 
{
    discordNickname = tmpDiscord;
}
void Coders::insertGithubLink(std::string tmpGit) 
{
    githubLink = tmpGit;
}
void Coders::insertFirecodeLink(std::string tmpFire) 
{
    firecodeLink = tmpFire;
}
void Coders::insertGroup(std::string tmpGroup) 
{
    group = tmpGroup;
}
*/
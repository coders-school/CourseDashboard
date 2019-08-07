#include "coders.hpp"
#include <iostream>

void Coders::printName(std::string tmpName) 
{
    name = tmpName;
    std::cout << name;
}
void Coders::printDiscordNickname(std::string tmpDiscord) 
{
    discordNickname = tmpDiscord;
    std::cout << discordNickname;
}
void Coders::printGithubLink(std::string tmpGit) 
{
    githubLink = tmpGit;
    std::cout << githubLink;
}
void Coders::printFirecodeLink(std::string tmpFire) 
{
    firecodeLink = tmpFire;
    std::cout << firecodeLink;
}
void Coders::printGroup(std::string tmpGroup) 
{
    group = tmpGroup;
    std::cout << group;
}



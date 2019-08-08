#include "Coders.hpp"
#include <iostream>

void Coders::printName() {std::cout << name;}
void Coders::printDiscordNickname() {std::cout << discordNickname;}
void Coders::printGithubLink() {std::cout << githubLink;}
void Coders::printFirecodeLink() {std::cout << firecodeLink;}
void Coders::printGroup() {std::cout << group;}
void Coders::insertName(std::string tmpName)
{
    name = tmpName;
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
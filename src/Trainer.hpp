#pragma once
#include "coders.hpp"

class Trainer : public virtual coders
{
    public:
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
};
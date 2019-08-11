#pragma once
#include <string>
#include <iostream>


class Coders
{
private:
    std::string userName;
    std::string discordNickname;
    std::string githubLink;
    std::string firecodeLink;
public: 
    enum class Group {weekends, evenings};
    Group SetGroup;
    Coders(std::string userName_,
           std::string discordNickname_, 
           std::string githubLink_,
           std::string firecodeLink_,
           Group SetGroup_);
    void printUserData();
    void insertDiscordNickname(std::string tmpDiscord);
    void insertName(std::string tmpName);
    void insertGithubLink(std::string tmpGit);
    void insertFirecodeLink(std::string tmpFire); 
    void insertGroup(Group tmpGroup);
    bool operator==(const Coders& tmpUser);
};
std::ostream& operator<<(std::ostream& screen, const Coders::Group& tmpGroup);

#pragma once

class Coders
{
    private:
    std::string name_;
    std::string discordNickname_;
    std::string githubLink_;
    std::string firecodeLink_;
    std::string group_;
    public: 
    Coders(std::string name,std::string discordNickname, std::string githubLink,
    std::string firecodeLink,std::string group);

    void printName();
    void printDiscordNickname();
    void printGithubLink();
    void printFirecodeLink();
    void printGroup();
    void insertDiscordNickname(std::string tmpDiscord);
    void insertName(std::string tmpName);
    void insertGithubLink(std::string tmpGit);
    void insertFirecodeLink(std::string tmpFire); 
    void insertGroup(std::string tmpGroup);
};
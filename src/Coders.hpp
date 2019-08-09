#include <string>
#include <iostream>
#include <cassert>

class Coders
{
    private:
    std::string userName;
    std::string discordNickname;
    std::string githubLink;
    std::string firecodeLink;
    std::string group;
    public: 
    Coders(std::string userName_,std::string discordNickname_, std::string githubLink_,
    std::string firecodeLink_,std::string group_);
    //friend std::ostream &operator << (std::ostream &out, const Coders &c);
    //friend std::ostream &operator >> (std::ostream &in, const Coders &c);
    //void printName();
    //void printDiscordNickname();
    //void printGithubLink();
    //void printFirecodeLink();
    //void printGroup();
    void insertDiscordNickname(std::string tmpDiscord);
    void insertName(std::string tmpName);
    void insertGithubLink(std::string tmpGit);
    void insertFirecodeLink(std::string tmpFire); 
    void insertGroup(std::string tmpGroup);
    //bool operator==(); // WIP
    //std::to_string printName();
    //std::to_string printDiscordNickname();
    //std::to_string printGithubLink();
    //std::to_string printFirecodeLink();
    //std::to_string printGroup();
std::string toString();
//~Coders(void);
};

   /* std::ostream &operator << (std::ostream &out, const Coders &c)
    {
        out << c.userName;
        //out << c.discordNickname;
        //out << c.githubLink;
        //out << c.firecodeLink;
        //out << c.group;
        return out;
    }
    std::ostream &operator >> (std::ostream &in, const Coders &c)
    {
        //out << "Please, write your name";
        in << c.userName;
        //out << "Please, write your Discord Nikename";
       // in << c.discordNickname;
        //out << "Please, write your github link";
       // in << c.githubLink;
        //out << "Please, write your firecode link";
       // in << c.firecodeLink;
        //out << "Please, write your group";
       // in << c.group;
        return in;
    }
    */
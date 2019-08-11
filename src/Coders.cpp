#include "Coders.hpp"
#include <iostream>
#include <string>


Coders::Coders(std::string userName_
             , std::string discordNickname_
             , std::string githubLink_
             , std::string firecodeLink_
             , Group SetGroup_)
             : userName(userName_)
             , discordNickname(discordNickname_)
             , githubLink(githubLink_)
             , firecodeLink(firecodeLink_)
             , SetGroup(SetGroup_){}
void Coders::insertName(std::string tmpName) {userName = tmpName;}
void Coders::insertDiscordNickname(std::string tmpDiscord) {discordNickname = tmpDiscord;}
void Coders::insertGithubLink(std::string tmpGit) {githubLink = tmpGit;}
void Coders::insertFirecodeLink(std::string tmpFire) {firecodeLink = tmpFire;}
void Coders::insertGroup(Group TmpGroup) {SetGroup = TmpGroup;};
void Coders::printUserData()
{
    std::cout << "Name = " << userName << std::endl;
    std::cout << "Discord nickname = " << discordNickname << std::endl;
    std::cout << "GitHub link = " << githubLink << std::endl;
    std::cout << "FireCode link = " << firecodeLink << std::endl;
    std::cout << "Group = " << SetGroup;
}
bool Coders::operator==(const Coders& tmpUser)
{
    return userName == tmpUser.userName;
}

std::ostream& operator<<(std::ostream& screen, const Coders::Group& tmpGroup)
{
    switch(tmpGroup)
    {
        case Coders::Group::weekends: screen << "weekends"; break;
        case Coders::Group::evenings: screen << "evenings"; break;
    }
    return screen;
}

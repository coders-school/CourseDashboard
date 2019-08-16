#include "stud.hpp"
#include <iostream>

 
 Student::Student(std::string nameVal,
                  std::string discordNameVal,
                  std::string gitLinkVal,
                  std::string groupNameVal,
                  std::string fireCodeVal)
     :
     name{nameVal},
     discordName{discordNameVal},
     gitLink{gitLinkVal},
     groupName{groupNameVal},
     fireCode{fireCodeVal}
 {}
 std::string Student :: getName()const
 {
     return name;
 }
 std::string Student :: getDiscordName()const
 {
     return discordName;
 }
 std::string Student :: getGitHubLink()const
 {
     return gitLink;
 }
 std::string Student :: getGroupName()const
 {
     return groupName;
 }
 std::string Student :: getFireCode()const
 {
     return fireCode;
 }
 void Student::view() const
 {
     std::cout << name << ", "<<discordName <<", "<<gitLink <<", " << groupName << ", " << fireCode << std::endl;
 }
 void Student :: setName(std::string nameVal)
 {
     name=nameVal;
 }
 void Student :: setDiscordName(std::string discorNameVal)
 {
     discordName=discorNameVal;
 }
 void Student :: setGitLink(std::string gitLinkVal)
 {
     gitLink=gitLinkVal;
 }
 void Student :: setGroup(std::string groupNameVal)
 {
     groupName=groupNameVal;
 }
 void Student :: setFireCode(std::string fireCodeVal)
 {
     fireCode=fireCodeVal;
 }

 std::ostream &operator << (std::ostream &out, const Student &c)
 {
     out << c.name << " " << c.discordName << " " << c.gitLink << " " << c.groupName << " " << c.fireCode << std::endl;
     return out;
 }


              




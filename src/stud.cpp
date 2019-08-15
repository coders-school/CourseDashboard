#include "stud.hpp"
#include <iostream>

 
 Student::Student(std::string nameVal, std::string discordNameVal, std::string gitLinkVal, std::string groupNameVal, std::string fireCodeVal)
     :
     name{nameVal},
     discordName{discordNameVal},
     gitLink{gitLinkVal},
     groupName{groupNameVal},
     fireCode{fireCodeVal}
 {

 }
 std::string Student :: getName()const
 {
     return name;
 }
 void Student::view() const
 {
     std::cout << name << ", "<<discordName <<", "<<gitLink <<", " << groupName << ", " << fireCode << std::endl;
 }
 std::ostream &operator << (std::ostream &out, const Student &c)
 {
     out << c.name << " " << c.discordName << " " << c.gitLink << " " << c.groupName << " " << c.fireCode << std::endl;
     return out;
 }

              




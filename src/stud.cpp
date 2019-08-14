 #include "stud.hpp"
 #include <iostream>

 
 Student::Student(std::string nameVal, std::string discordNameVal, std::string gitLinkVal, std::string groupNameVal)
     :
     name{nameVal},
     discordName{discordNameVal},
     gitLink{gitLinkVal},
     groupName{groupNameVal}
 {

 }
 void Student::view() const
 {
     std::cout<<name << ", "<<discordName<<", "<<gitLink<<", "<<groupName<<std::endl;
 }

              




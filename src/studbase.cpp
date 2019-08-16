 #include "studbase.hpp"
 #include <iostream>
 #include <string>
 #include <iterator>
 #include <algorithm>

 void StudentData::addUser(const Student & student)
 {
    studData.emplace_back(student);
 }

 void StudentData::viewUsers()
 {
     int i {0};
     for (const auto &student : studData)
     {
         i++;
         std::cout<<i<<" ";
         student.view();
     }
 }

 void StudentData::deleteUser(std::string name)
 {
    auto it = std::find_if(std::begin(studData),std::end(studData), [name](const auto & stud)
    {
        return stud.getName()==name;
    });

    if (it !=std::end(studData))
    {
        studData.erase(it);
    }
 }
 void StudentData::editUser(Student & stud)
 {
     std::string nameVal,discordNameVal,gitLinkVal,groupVal,fireCodeVal;
     std::cout<<"Edit student data: "<<std::endl;
     std::cout<<"New name: ";
     std::cin>>nameVal;
     stud.setName(nameVal);
     std::cout<<"New discord name: ";
     std::cin>>discordNameVal;
     stud.setDiscordName(discordNameVal);
     std::cout<<"New github link: ";
     std::cin>>gitLinkVal;
     stud.setGitLink(gitLinkVal);
     std::cout<<"New group: ";
     std::cin>>groupVal;
     stud.setGroup(groupVal);
     std::cout<<"New firecode link: ";
     std::cin>>fireCodeVal;
     stud.setFireCode(fireCodeVal);
 }
 bool StudentData::isNameMissingInData(const Student &student)
 {
     return (student.getName() == "");
 }





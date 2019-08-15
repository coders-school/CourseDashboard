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
// std::ostream &operator <<(std::ostream &out, const StudentData &c)
// {
//     out<<c.name<<" "<<c.discordName<<" "<<c.gitLink<<" "<<c.groupName<<std::endl;
//     return out;
// }
 //void Trainer::editUser(int userNumber,std::string name, std::string surname,  std::string discordName)
 //{
 //    std::string temp {name,surname,discordName};
 //    trainer.swap(temp.begin()+userNumber);
 //}





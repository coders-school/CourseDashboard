 #include "train.hpp"
 #include <iostream>
 #include <string>
 #include <iterator>
 
 
 StudentData::StudentData()
 {
 }
 void StudentData::addUser(std::string name, std::string discordName, std::string gitLink, std::string group)
 {
     studData.emplace_back(name, discordName, gitLink, group);
 }
 
 void StudentData::viewUsers()
 {
     int i {0};
     for (const auto &student: studData)
     {
         i++;
         std::cout<<i<<" ";
         student.view();
    }
 }

 void StudentData::deleteUser(int userNumber)
 {
     studData.erase(studData.begin()+userNumber);
 }
 //void Trainer::editUser(int userNumber,std::string name, std::string surname,  std::string discordName)
 //{
 //    std::string temp {name,surname,discordName};
 //    trainer.swap(temp.begin()+userNumber);
 //}





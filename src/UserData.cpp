#include <iostream>
#include <string>
#include "UserData.hpp"
#include <functional>

namespace
{
    void printMenu()
    {
         std::system("clear");
         std::cout << "Change: " << std::endl;
         std::cout << "======================================" << std::endl;
         std::cout << "1. Name" << std::endl;
         std::cout << "2. Nick" << std::endl;
         std::cout << "3. Firecode link: " << std::endl;
         std::cout << "4. Github link" << std::endl;
         std::cout << "5. Group" << std::endl;
         std::cout << "6. Exit" << std::endl;
         std::cout << "======================================" << std::endl;

         std::cout << "Which information would You like to change?" << std::endl;
         std::cout << "[To go next, input number from 1 to 6]" << std::endl;
    }

    void change(std::istream &in, std::function <void (std::string)> setter, std::string prompt)
    {
        std::string data;
        std::cout << prompt << ": ";
        in >> data;
        setter(data);
    }
}

UserData::UserData(std::string name, std::string nick, std::string firecodeLink, std::string githubLink, Group group) 
    : name_(name)
    , nick_(nick)
    , firecodeLink_(firecodeLink)
    , githubLink_(githubLink)
    , group_(group)
    {}

void UserData::setName(std::string name)
{
    name_ = name;
}

std::string UserData::getName() const
{
    return name_;
}

void UserData::setNick(std::string nick) 
{
    nick_ = nick;
}

std::string UserData::getNick() const
{
    return nick_;
}

void UserData::setFirecodeLink(std::string firecodeLink)
{
    firecodeLink_ = firecodeLink;
}

std::string UserData::getFirecodeLink() const
{
    return firecodeLink_;
}

void UserData::setGithubLink(std::string githubLink)
{
    githubLink_ = githubLink;
}

std::string UserData::getGithubLink() const
{
    return githubLink_;
}

void UserData::setGroup(Group group)
{
    group_ = group;
}

Group UserData::getGroup() const
{
    return group_;
}

std::ostream &operator << (std::ostream &out, const UserData &user)
     {
         out << "Name: " << user.name_ << std::endl;
         out << "Nick: " << user.nick_ << std::endl;
         out << "Firecode link: " << user.firecodeLink_ << std::endl;;
         out << "Github link: " << user.githubLink_ << std::endl;
         out << "Group: " << user.group_ << std::endl;
         return out;
     }


std::istream &operator >> (std::istream &in,  UserData &user)
     {
         int choice=0;
         do
          {
             printMenu();
             int choice;
             in >> choice;
             std::system("clear");

                 switch(choice)
                 {
                     case 1:
                         {
                            auto lambda = [&user](std::string data){user.setName(data);};
                            change(in, lambda, "New name");
                            break;
                         }
                     case 2:
                         {
                            auto lambda = [&user](std::string data){user.setNick(data);};
                            change(in, lambda, "New nick");
                            break;
                         }
                     case 3:
                         {
                            auto lambda = [&user](std::string data){user.setFirecodeLink(data);};
                            change(in, lambda, "New firecode link");
                            break;
                         }
                     case 4:
                         {
                            auto lambda = [&user](std::string data){user.setGithubLink(data);};
                            change(in, lambda, "New github link");
                            break;
                         }
                     case 5:
                         {
                             std::cout << "Change group to: " << std::endl;
                             std::cout << "1. weekend" << std::endl;
                             std::cout << "2. evening" << std::endl;
                             int pick;
                             std::cin >> pick;

                             switch(pick)
                             {
                                 case 1:
                                     {
                                         if(user.getGroup() == Group::weekend)
                                         {
                                             std::system("clear");
                                             break;
                                         }
                                         else
                                         {
                                             user.setGroup(Group::weekend);
                                             std::system("clear");
                                             return in;
                                         }
                                         break;
                                     }
                                 case 2:
                                     {
                                         if(user.getGroup() == Group::evening)
                                         {
                                             std::system("clear");
                                             break;
                                         }
                                         else
                                         {
                                             user.setGroup(Group::evening);
                                             std::system("clear");
                                         }
                                         break;
                                     }
                             }
                             break;
                         }
                     case 6:
                         {
                             return in;
                             break;
                         }
                     default: break;
                 }

          } while(choice!=6);
         return in;
     }


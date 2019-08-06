#include <string>
#include "Group.hpp"
#include <iostream>

class UserData
{
    public:
    UserData(std::string name, std::string nick, std::string firecodeLink, std::string githubLink, Group group);
    
    std::string getName() const;
    void setName(std::string name);

    std::string getNick() const;
    void setNick(std::string nick);

    std::string getFirecodeLink() const;
    void setFirecodeLink(std::string firecodeLink);

    std::string getGithubLink() const;
    void setGithubLink(std::string githubLink);

    Group getGroup() const;
    void setGroup(Group group);

    friend std::ostream &operator << (std::ostream &out, const UserData &user);
    friend std::istream &operator >> (std::istream &in, UserData &user);

    private:
    std::string name_;
    std::string nick_;
    std::string firecodeLink_;
    std::string githubLink_;
    Group group_;

};

    inline std::ostream &operator << (std::ostream &out, const UserData &user)
    {
        out << "Name: " << user.name_ << std::endl;      
        out << "Nick: " << user.nick_ << std::endl;
        out << "Firecode link: " << user.firecodeLink_ << std::endl;;
        out << "Github link: " << user.githubLink_ << std::endl;
        out << "Group: " << user.group_ << std::endl;
        return out;
    }

    inline  std::istream &operator >> (std::istream &in,  UserData &user)
    {
        int choice=0;
        do
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
            
            int choice;
            in >> choice;
            std::system("clear"); 
        
                switch(choice)
                {
                    case 1: 
                        {
                            std::cout << "New name: ";
                            std::string newName;
                            in >> newName;
                            user.setName(newName);
                            std::system("clear");
                            break;
                        }
                    case 2:
                        {
                            std::cout << "New nick: ";
                            std::string newNick;
                            in >> newNick;
                            user.setNick(newNick);
                            std::system("clear");
                            break;
                        }
                    case 3:
                        {
                            std::cout << "New firecode link: ";
                            std::string newFirecodeLink;
                            in >> newFirecodeLink;
                            user.setFirecodeLink(newFirecodeLink);
                            std::system("clear");
                            break;
                        }
                    case 4:
                        {
                            std::cout << "New github link: ";
                            std::string newGithubLink;
                            in >> newGithubLink;
                            user.setGithubLink(newGithubLink);
                            std::system("clear");
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


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

  

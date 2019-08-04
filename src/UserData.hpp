#include <string>
#include "Group.hpp"
class UserData
{
    std::string name_;
    std::string nick_;
    std::string firecodeLink_;
    std::string githubLink_;
    Group group_;
    public:
    UserData(std::string name, std::string nick, std::string firecodeLink, std::string githubLink);
    
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
};

#include <string>
class UserData
{
    std::string name_;
    std::string nick_;
    std::string firecodeLink_;
    std::string githubLink_;
    
    public:
    
    UserData(){};
    
    std::string getName() const;
    void setName(std::string);

    std::string getNick() const;
    void setNick(std::string);

    std::string getFirecodeLink() const;
    void setFirecodeLink(std::string);

    std::string getGithubLink() const;
    void setGithubLink(std::string);
};

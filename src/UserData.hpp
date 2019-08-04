#include <string>
class UserData
{
    std::string name;
    std::string nick;
    std::string firecodeLink;
    std::string githubLink;
    
    public:
    
    UserData(){};
    
    std::string getName();
    void setName(std::string);

    std::string getNick();
    void setNick(std::string);

    std::string getFirecodeLink();
    void setFirecodeLink(std::string);

    std::string getGithubLink();
    void setGithubLink(std::string);
};

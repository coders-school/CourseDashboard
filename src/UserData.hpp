#include <string>
class UserData
{
    std::string name;
    std::string nick;
    std::string firecodeLink;
    std::string githubLink;
    
    public:
    
    UserData(){};
    
    const std::string getName();
    void setName(std::string);

    const std::string getNick();
    void setNick(std::string);

    const std::string getFirecodeLink();
    void setFirecodeLink(std::string);

    const std::string getGithubLink();
    void setGithubLink(std::string);
};

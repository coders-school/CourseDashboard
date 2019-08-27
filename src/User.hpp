#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class User
{
public:
    User() = default;
    User(const std::string & name,
         const std::string & nick,
         const std::string & group,
         const std::string & gitHub,
         const std::string & firecode);
   
    std::string getAllInfo() const;
    std::string getAllInfoToFile() const;
    void setName(std::string name);
    void setNick(std::string nick);
    void setGroup(std::string group);
    void setGitHub(std::string gitHub);
    void setFirecode(std::string firecode);
    std::string getNick() const;

private:

    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;  

};

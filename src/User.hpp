#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class User
{
public:
    User(const std::string & name,
         const std::string & nick,
         const std::string & group,
         const std::string & gitHub,
         const std::string & firecode,
         const std::string & email,
         const std::string & password);
   
    std::string getAllInfo() const;
    void setName(std::string name);
    void setNick(std::string nick);
    void setGroup(std::string group);
    void setGitHub(std::string gitHub);
    void setFirecode(std::string firecode);
    void setEmail(std::string email);
    void setPassword(std::string password);
    std::string getNick() const;

private:
    
    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;  
    std::string email_;
    std::string password_;
};

#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class User
{
public:
    User(const std::string & name,
         const std::string & nick,
         const std::string & password,
         const std::string & mail,
         const std::string & group,
         const std::string & gitHub,
         const std::string & firecode);
    
    void setName(std::string name);
    void setNick(std::string nick);
    void setPassword(std::string password);
    void setMail(std::string mail);
    void setGroup(std::string group);
    void setGitHub(std::string gitHub);
    void setFirecode(std::string firecode);
    
    // std::string getName() const;
    std::string getNick() const;
    // std::string getPassword() const;
    // std::string getMail() const;
    // std::string getGroup() const;
    // std::string getGitHub() const;
    // std::string getFirecode() const;
    std::string getAllInfo() const;

    std::string serialize();
    
private:
    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;  
    std::string password_;
    std::string mail_;
};

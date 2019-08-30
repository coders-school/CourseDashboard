#pragma once
#include <string>
#include <sstream>
#include <iomanip>


class User
{
    friend std::ostream &operator << (std::ostream &out, const User &c);

public:
    User(const std::string & name,
         const std::string & nick,
         const std::string & group,
         const std::string & gitHub,
         const std::string & firecode,
         const std::string & email,
         const std::string & password);
   
    std::string getAllInfo() const;
    bool setName(std::string name);
    bool setNick(std::string nick);
    bool setGroup(std::string group);
    bool setGitHub(std::string gitHub);
    bool setFirecode(std::string firecode);
    bool setEmail(std::string email);
    bool setPassword(std::string password);
    std::string getNick() const;
    std::string getEmail() const;
    std::string getPassword() const;

private:
    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;
    std::string email_;
    std::string password_;  
    

};

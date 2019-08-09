#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include "Users.hpp"
class User
{

public:

    User(const std::string & name,
            const std::string & nick,
            const std::string & group,
            const std::string & gitHub,
            const std::string & firecode);
   
    std::string getAllInfo() const;
    void updateUser();
    void deleteUser(User user);
    void addUser(const User &  User);
    void getAllInfoEveryone(const std::vector<User> & v);
private:

    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;  

};

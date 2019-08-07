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
            const std::string & firecode);
   
    std::string getAllInfo() const;

private:

    std::string name_;
    std::string nick_;
    std::string group_;
    std::string gitHub_;
    std::string firecode_;  

};
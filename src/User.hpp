#pragma once
#include <string>
#include "nlohmann/json.hpp"

class User
{
public:
    enum class Group
    {
        weekend,
        evening
    };

    User(const std::string & name,
         const std::string & nick,
         Group group,
         const std::string & gitHub,
         const std::string & firecode);

    User(nlohmann::json userJson);
   
    std::string getAllInfo() const;
    nlohmann::json toJson() const;

    void setName(const std::string & name);
    void setNick(const std::string & nick);
    void setGroup(Group group);
    void setGitHub(const std::string & gitHub);
    void setFirecode(const std::string & firecode);
    std::string getNick() const;

private:
    std::string name_;
    std::string nick_;
    Group group_;
    std::string gitHub_;
    std::string firecode_;  

};

using Users = std::vector<User>;

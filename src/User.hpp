#pragma once
#include <string>
#include "nlohmann/json.hpp"

class User
{
public:
    enum class Group
    {
        weekend,
        evening,

        ALL,
    };

    User(const std::string & name,
         const std::string & nick,
         Group group,
         const std::string & gitHub,
         const std::string & firecode,
         const std::string &email = "",
         const std::string &password = "");

    User(nlohmann::json userJson);
   
    std::string toString() const;
    nlohmann::json toJson() const;

    void setName(std::string_view name);
    void setNick(std::string_view nick);
    void setGroup(Group group);
    void setGitHub(std::string_view gitHub);
    void setFirecode(std::string_view firecode);
    std::string getName() const;
    std::string getNick() const;
    std::string getEmail() const;
    std::string getPassword() const;

    friend bool operator==(const User &lhs, const User& rhs);

private:
    std::string name_;
    std::string nick_;
    Group group_;
    std::string gitHub_;
    std::string firecode_;
    std::string email_;
    std::string password_;

};

using Users = std::vector<User>;

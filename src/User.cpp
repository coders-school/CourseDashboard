#include "User.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

User::User(const std::string &name,
           const std::string &nick,
           Group group,
           const std::string &gitHub,
           const std::string &firecode,
           const std::string &email,
           const std::string &password)
    : hash_(PasswordHashingProvider(16,16))
    , name_(name)
    , nick_(nick)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
    , email_(email)
    , salt_(hash_.generateSalt())
    , hashedPassword_(hash_.generateHash(salt_, password))
{}

User::User(nlohmann::json userJson)
    : name_(userJson["name"].get<std::string>())
    , nick_(userJson["nick"].get<std::string>())
    , group_(userJson["group"].get<Group>())
    , gitHub_(userJson["gitHub"].get<std::string>())
    , firecode_(userJson["firecod"].get<std::string>())
{}

std::string User::toString() const
{
    std::stringstream ss;
    ss << std::left;
    ss << std::setw(1) << "1." << name_ << "|";
    ss << std::setw(1) << "2." << nick_ << "|";
    ss << std::setw(1) << "3." << (group_ == Group::weekend ? "weekend" : "evening") << "|";
    ss << std::setw(1) << "4." << gitHub_ << "|";
    ss << std::setw(1) << "5." << firecode_ << "|";
    ss << std::endl;
    return ss.str();
}

nlohmann::json User::toJson() const
{
    nlohmann::json uJson = {
        {"name", name_},
        {"nick", nick_},
        {"group", group_},
        {"gitHub", gitHub_},
        {"firecod", firecode_}};
    return uJson;
}

void User::setName(std::string_view name) { name_ = name; }
void User::setNick(std::string_view nick) { nick_ = nick; }
void User::setGroup(Group group) { group_ = group; }
void User::setGitHub(std::string_view gitHub) { gitHub_ = gitHub; }
void User::setFirecode(std::string_view firecode) { firecode_ = firecode; }

std::string User::getNick() const { return nick_; }

bool operator==(const User &lhs, const User &rhs)
{
    return (lhs.name_ == rhs.name_ &&
            lhs.nick_ == rhs.nick_ &&
            lhs.group_ == rhs.group_ &&
            lhs.gitHub_ == rhs.gitHub_ &&
            lhs.firecode_ == rhs.firecode_);
}

std::string User::getEmail() const
{
    return email_;
}

bool User::validatePassword(const std::string& password) const {
    return !hashedPassword_.compare(hash_.generateHash(salt_, password));
}

bool User::validateEmail(const std::string& email) const {
    if (!email.empty() && (email.size() == email_.size())) {
        for(std::size_t i=0; i<email.size(); ++i) {
            if(tolower(email[i]) != tolower(email_[i]))
                return false;            
        }
    }
    else {
        return false;
    }
    return true;
}

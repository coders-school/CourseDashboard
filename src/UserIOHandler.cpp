#include "UserIOHandler.hpp"
#include "nlohmann/json.hpp"

#include <ios>
#include <iostream>
#include <string>

UserIOHandler::UserIOHandler(IFstream* fs)
:fs_(fs)
{
}

void UserIOHandler::write(const std::string& content)
{
    try
    {
        fs_->tryToWrite(content);
    }
    catch(std::ios_base::failure& e)
    {
        std::cerr << "Write to file: " << fs_->getFilePath() << "failed.\n"
            << "Error message: " << e.what() << "\n";
    }
}

std::string UserIOHandler::read()
{
    std::string read;

    try
    {
        read = fs_->tryToRead();
    }

    catch(std::ios_base::failure& e)
    {
        std::cerr << "Read from file: " << fs_->getFilePath() << "failed.\n"
            << "Error message: " << e.what() << "\n";
        return "";
    }

    return read;
}

std::string UserIOHandler::convertToJson( const std::vector<User>& users )
{
    nlohmann::json jsonArray = nlohmann::json::array();

    for(auto user : users)
    {
        nlohmann::json userJson = {
            { "name", user.getName()},
            { "nick", user.getNick()},
            { "group", user.getGroup()},
            { "gitHub", user.getGitHub()},
            { "firecode", user.getFirecode()}
        };

        jsonArray.push_back(userJson);
    }

    return jsonArray.dump();
}

std::vector<User> UserIOHandler::convertToArray(const std::string& jsonString)
{
    nlohmann::json jsonArray = nlohmann::json::parse(jsonString);

    std::vector<User> users;
    for(auto& jsonE : jsonArray)
    {
        auto name = jsonE["name"].get<std::string>();
        auto nick = jsonE["nick"].get<std::string>();
        auto group = jsonE["group"].get<std::string>();
        auto gitHub = jsonE["gitHub"].get<std::string>();
        auto firecode = jsonE["firecode"].get<std::string>();

        users.push_back(User(name, nick, group, gitHub, firecode));
    }


    return users;
}
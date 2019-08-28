#include "UserIOHandler.hpp"
#include "../external/nlohmann/json.hpp"

#include <ios>
#include <iostream>
#include <string>

// using fstreamPtr = std::unique_ptr<std::fstream, std::function<void(std::fstream*)>>;
// using ifstreamPtr = std::unique_ptr<std::ifstream>;

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

std::string UserIOHandler::convertUsersToJson(std::vector<User> users)
{
    nlohmann::json jsonArray = nlohmann::json::array();

    for(auto user : users)
    {
        nlohmann::json userJson = {
            { "name", user.getName()},
            { "nick", user.getNick()},
            { "group", user.getGroup()},
            { "gitHub", user.getGitHub()},
            { "firecod", user.getFirecod()}                
        };

        jsonArray.push_back(userJson);
    }

    return jsonArray.dump();
}
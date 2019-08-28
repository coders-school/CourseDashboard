#pragma once

#include "IFstream.hpp"
#include "User.hpp"

#include <string>
#include <vector>

class UserIOHandler
{

public:
    explicit UserIOHandler(IFstream* fs);
    ~UserIOHandler() = default;
    void write(const std::string& content);
    std::string read();
    
    std::string convertToJson(const std::vector<User>& users);
    std::vector<User> convertToArray(const std::string& jsonString);

private:

    

    IFstreamPtr fs_;
};
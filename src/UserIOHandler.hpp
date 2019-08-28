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
    
    std::string convertUsersToJson(std::vector<User> users);

private:

    

    IFstreamPtr fs_;
};
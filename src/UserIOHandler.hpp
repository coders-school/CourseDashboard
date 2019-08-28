#pragma once

#include "IFstream.hpp"

#include <string>
#include <vector>

class UserIOHandler
{

public:
    explicit UserIOHandler(IFstream* fs);
    ~UserIOHandler() = default;
    void write(const std::string& content);
    std::string read();

private:
    IFstreamPtr fs_;
};

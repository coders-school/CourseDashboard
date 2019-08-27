#pragma once

#include "IFstream.hpp"

#include <string>

class UserIOHandler
{

public:
    explicit UserIOHandler(IFstream* fs);
    ~UserIOHandler() = default;
    void write(const std::string& content);
    void read(const std::string& filePath, std::string& strBuff);
private:
    IFstreamPtr fs_;
};
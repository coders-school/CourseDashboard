#pragma once

#include <string>

class UserIOHandler
{

public:
    explicit UserIOHandler() = default;
    ~UserIOHandler() = default;
    void write(const std::string& filePath, const std::string& strBuff);
};
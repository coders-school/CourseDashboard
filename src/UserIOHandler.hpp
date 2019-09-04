#pragma once
#include <string>


class UserIOHandler
{
public:
    explicit UserIOHandler(const std::string& filePath);
    void write(const std::string& content) const;
    std::string read() const;

private:
    std::string filePath_;
};

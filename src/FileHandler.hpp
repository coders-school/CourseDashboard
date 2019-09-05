#pragma once
#include <string>


class FileHandler
{
public:
    explicit FileHandler(const std::string& filePath);
    void write(const std::string& content) const;
    std::string read() const;

private:
    std::string filePath_;
};

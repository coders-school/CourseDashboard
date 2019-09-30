#include "FileHandler.hpp"
#include <iostream>
#include <fstream>


FileHandler::FileHandler(const std::string& filePath)
    : filePath_(filePath)
{}

void FileHandler::write(const std::string& content) const
{
    std::ofstream file(filePath_);
    file.write(content.c_str(), content.size());
}

std::string FileHandler::read() const
{
    std::ifstream file(filePath_);
    if (not file.good())
        throw std::invalid_argument{"File " + filePath_ + " not found"};

    std::string read{};
    while (not file.eof()) {
        read.push_back(file.get());
    }
    read.pop_back();
    return read;
}

#include "FileHandler.hpp"
#include <iostream>
#include <fstream>


FileHandler::FileHandler(const std::string& filePath)
    :filePath_(filePath)
{}

void FileHandler::write(const std::string& content) const
{
    try
    {
        std::ofstream file(filePath_);
        file.write(content.c_str(), content.size());
    }
    catch(std::ios_base::failure& e)
    {
        std::cerr << "Write to file: " << filePath_ << "failed.\n"
                  << "Error message: " << e.what() << "\n";
    }
}

std::string FileHandler::read() const
{
    std::string read{};

    try
    {
        std::ifstream file(filePath_);
        while(!file.eof()) {
            read.push_back(file.get());
        }
        read.pop_back();
    }
    catch(std::ios_base::failure& e)
    {
        std::cerr << "Read from file: " << filePath_ << "failed.\n"
                  << "Error message: " << e.what() << "\n";
    }

    return read;
}

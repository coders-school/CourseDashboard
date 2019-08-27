#include "UserIOHandler.hpp"

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

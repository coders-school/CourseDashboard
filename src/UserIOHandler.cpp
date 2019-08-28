#include "UserIOHandler.hpp"
#include "nlohmann/json.hpp"

#include <ios>
#include <iostream>
#include <string>

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

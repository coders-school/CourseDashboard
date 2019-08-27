#include "UserIOHandler.hpp"

#include <ios>
#include <iostream>
#include <string>

using fstreamPtr = std::unique_ptr<std::fstream, std::function<void(std::fstream*)>>;
using ifstreamPtr = std::unique_ptr<std::ifstream>;

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

void UserIOHandler::read(const std::string& filePath, std::string& strBuff)
{
    ifstreamPtr file(new std::ifstream());

    try
    {
        file->open(filePath, std::fstream::out);
        while(!file->eof()) {
            strBuff.push_back(file->get());
        }
        strBuff.pop_back();
    }

    catch(std::ios_base::failure& e)
    {
        std::cerr << "Read from file: " << filePath << "failed.\n"
            << "Error message: " << e.what() << "\n";
    }
}

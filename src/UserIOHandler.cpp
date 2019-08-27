#include "UserIOHandler.hpp"

#include <fstream>
#include <functional>
#include <ios>
#include <iostream>
#include <memory>
#include <string>

using fstreamPtr = std::unique_ptr<std::fstream, std::function<void(std::fstream*)>>;
using ifstreamPtr = std::unique_ptr<std::ifstream>;

void UserIOHandler::write(const std::string& filePath, const std::string& strBuff)
{
    fstreamPtr file(new std::fstream(), 
        [](std::fstream* f)
        {
            if(f->is_open())
            {
                f->close();
            }
        });
    
    file->exceptions(std::ios_base::badbit);

    try
    {
        file->open(filePath, std::fstream::out);
    }

    catch(std::ios_base::failure& e)
    {
        std::cerr << "Write to file: " << filePath << "failed.\n"
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

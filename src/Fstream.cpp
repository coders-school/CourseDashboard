#include "Fstream.hpp"
#include <fstream>


Fstream::Fstream(const std::string& filePath)
    : filePath_(filePath)
{}

void Fstream::tryToWrite(const std::string& content) const
{
    try
    {
        std::ofstream file(filePath_);
        file.write(content.c_str(), content.size());
    }
    catch (std::ios_base::failure& e)
    {
        throw;
    }
}

std::string Fstream::tryToRead() const
{
    std::string strBuff {};

    try
    {
        std::ifstream file(filePath_);
        while(!file.eof()) {
            strBuff.push_back(file.get());
        }
        strBuff.pop_back();
    }
    catch(std::ios_base::failure& e)
    {
        throw;
    }

    return strBuff;
}

std::string Fstream::getFilePath() const
{
    return filePath_;
}

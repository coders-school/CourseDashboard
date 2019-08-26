#include "CourseDashboard.hpp"
#include <fstream>

CourseDashboard::CourseDashboard() {}

bool CourseDashboard::savingToFile(User & c)
{
    std::ofstream out_file{ "../ParticipantsDetails.txt", std::ios::app };
    if (!out_file)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
        out_file << c;
        out_file.close();
        return true;
}
bool CourseDashboard::readingFromFile()
{
    std::ifstream in_file{"../ParticipantsDetails.txt"};
    if (!in_file)
    {
       std::cerr << "Error" << std::endl;
       return false;
    }
    std::string text{};
    std::cout << "Reading from file ..." << std::endl;
    std::cout << "=====================" << std::endl;
    while (std::getline(in_file,text))
    {
        std::cout << text << std::endl;
    }
    std::cout << "=====================" << std::endl;
    in_file.close();
    return true;
}

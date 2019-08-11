#include<CourseDashboard.hpp>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iterator>
#include<vector>

std::vector<std::string> CourseDashboard::readData(std::string fileName, int lineNumber)
{
    std::fstream file; 
    file.open(fileName, std::ios::in);

    if (file.good() == false)
    {   
        std::cout << "No such file in current directory! \n";
        exit(0);
    }   

    std::string line;
    std::string dataLine;
    int i = 0;

    while(getline(file,line))
    {   
        if (i == lineNumber)
        {   
            dataLine = line;
            break;
        }   
        else i++;
    }   
    file.close();    

    std::istringstream iss(dataLine);
    std::vector<std::string> words;

    copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), back_inserter(words));

    return words;
}

void CourseDashboard::printVs(std::vector<std::string> pvs)
{
    for (auto i: pvs){std::cout << i << " ";}
    std::cout << "\n";
}



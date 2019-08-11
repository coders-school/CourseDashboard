#pragma once
#include<string>

class CourseDashboard
{
public:
    // Constructors
    CourseDashboard(){};

    // Methods

    // --> read dataline and converts to vector
    std::vector<std::string> readData(std::string fileName, int line);

    // --> print vector of strings
    void printVs(std::vector<std::string> pvs);
    
};

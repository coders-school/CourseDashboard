#include <iostream>
#include "CourseDashboard.hpp"
#include "User.hpp"
#include "Server.hpp"

int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;

    Server server1;   
    server1.downloadUsers();

    //cdb.saveToFile("userDatabase.txt");
    //cdb.loadFromFile("userDatabase.txt");

    return 0;
}

#include <iostream>
#include "CourseDashboard.hpp"
#include "User.hpp"
#include "Server.hpp"

int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    Server server1;   

    if (server1.checkIfFileExist())
    {
        std::cout << "OK\n";
        server1.downloadUsers();
        //server1.checkConnection();
    }
    else
        std::cout << "NOT OK\n";


    //cdb.saveToFile("userDatabase.txt");
    //cdb.loadFromFile("userDatabase.txt");

    return 0;
}

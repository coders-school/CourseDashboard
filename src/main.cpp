#include <iostream>
#include <fstream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    cdb.logIn();
    User u1("Jan", "JanKowalsky", "wieczorowa", "JanKowalsky", "JanKowalsky");
    cdb.createUser(u1);
    cdb.retriveUserByNick("JanKowalsky");
    cdb.showAll();
    cdb.deleteUserByNick("JanKowalsky");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}

#include <iostream>
#include <fstream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    cdb.logIn();
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    cdb.createUser(u1);
    cdb.retriveUserByNick("SzymonGajewski");
    cdb.showAll();
    cdb.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}

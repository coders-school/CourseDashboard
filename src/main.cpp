#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    cdb.loadFromFile();
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    cdb.createUser(u1);
    User u2("Jan", "JanKowalski", "weekendowa", "JanKowalski", "JanKowalski");
    cdb.createUser(u2);
    cdb.showAll();
    cdb.saveUsersToFile(cdb.getVector());
    cdb.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}

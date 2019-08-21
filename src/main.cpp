#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    cdb.createUser(u1);
    cdb.retriveUserByNick("SzymonGajewski");
    //cdb.loadUserFromFile();
    User u2("Jan Kowalski", "Jan123", "weekendowa", "JanK", "JanK");
    cdb.createUser(u2);
    //cdb.writeUserToFile(u2);
    cdb.showAll();
    cdb.saveToFile();
    return 0;
}

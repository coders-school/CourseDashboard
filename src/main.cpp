#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "mail@com", "password");
    cdb.addTrainer("Lukin");
    cdb.createUser(u1);
    cdb.logIn();
    cdb.retriveUserByNick("SzymonGajewski");
    cdb.showAll();
    cdb.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}

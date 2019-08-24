#include <iostream>
#include "CourseDashboard.hpp"



int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    User u2("test0", "test1", "test2", "test3", "test4");
    cdb.createUser(u1);
    cdb.createUser(u2);
//    cdb.retriveUserByNick("SzymonGajewski");
    cdb.showAll();
    cdb.readingFromFile();
    cdb.savingToFile(u1);
    cdb.savingToFile(u2);
    cdb.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}

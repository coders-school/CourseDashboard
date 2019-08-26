#include <iostream>
#include "CourseDashboard.hpp"



int main()
{
//    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    User u2("test0", "test1", "test2", "test3", "test4");
    UserData usd;
    usd.createUser(u1);
    usd.createUser(u2);
//    cdb.retriveUserByNick("SzymonGajewski");
    usd.showAll();
    usd.readingFromFile();
    usd.savingToFile(u1);
    usd.savingToFile(u2);
    usd.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    usd.showAll();
    return 0;
}

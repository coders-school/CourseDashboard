#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "szymomn@gmail.com", "12345678");
    User u2("test0", "test1", "test2", "test3", "test4", "test5", "test6");
    UserData usd;
    usd.createUser(u1);
    usd.createUser(u2);
    usd.showAll();
    cdb.readingFromFile();
    cdb.savingToFile(u1);
    cdb.savingToFile(u2);
    usd.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    usd.showAll();
    Login log;
    bool logged = log.LogInToTheApplication(u2,"test5", "test6");
    std::cout << logged <<std::endl;
    return 0;
}
